#include <fingerprint_emitter.h>

Fingerprint_Emitter::Fingerprint_Emitter(const Fingerprint &data) : current_stage(Stage::Control_Package),
                                                                    m_data(data)
{
}

bool Fingerprint_Emitter::send()
{
    //create shared memory - aquire it's id
    int shared_package_id;
    //note to self - 0666 is wierd AF bitmask - do not touch
    int key_id = 9877;
    shared_package_id = shmget(key_t(key_id), sizeof(Package), 0666);

    if (shared_package_id < 0)
    {
        //TODO error handling
        std::cout << "shmget memory aquisition error" << std::endl;
        return false;
    }

    //project shared memory in the scope of the function
    void *shared_package;
    shared_package = shmat(shared_package_id, NULL, 0);

    while (current_stage != Stage::Finished)
    {
        Package current_package = extract_package();

        //send a package
        std::memcpy(shared_package, &current_package, sizeof(Package));
        static_cast<Package *>(shared_package)->change_status(Package_Status::Sent);
        static_cast<Package *>(shared_package)->show();

        //await response
        while (static_cast<Package *>(shared_package)->get_status() !=
               Package_Status::Recieved)
        {
            //do nothing i gues...
        }
        std::cout << "package recieved" << std::endl;
    }
    std::cout << "conversation finished. Terminating connection" << std::endl;
    return true;
}

Package Fingerprint_Emitter::extract_package()
{
    Package message;
    switch (current_stage)
    {
    case Stage::Control_Package:
        message = Package(std::to_string(m_data.get_size()), Package_Type::Control);
        current_stage = Stage::Data_Package;
        break;

    case Stage::Data_Package:
        message = Package(m_data[current_id], Package_Type::Data);
        ++current_id;
        if (current_id == m_data.get_size())
            current_stage = Stage::Finished;
        break;

    default:
        break;
    }
    return message;
}