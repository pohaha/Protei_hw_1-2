#include <fingerprint_emitter.h>

Fingerprint_Emitter::Fingerprint_Emitter(const Fingerprint& data):
    current_stage(Stage::Control_Package),
    m_data(data)
{}

bool Fingerprint_Emitter::send()
{
    //create shared memory - aquire it's id
    int shared_status_memory_id;
    int shared_package_id;
        //note to self - 0666 is wierd AF bitmask - do not touch
    shared_package_id = shmget(key_t(9877), sizeof(Package), IPC_CREAT | 0666);
    shared_status_memory_id = shmget(key_t(9876), sizeof(int), IPC_CREAT | 0666);
    if((shared_status_memory_id < 0) ||  //or
       (shared_package_id < 0))
    {   
        //TODO error handling
        std::cout<<"shmget memory aquisition error"<<std::endl;
        return false;
    }
    
    //project shared memory in the scope of the function
    void* message_box;
    void* protocol;
    message_box = shmat(shared_package_id, NULL, 0);
    protocol = shmat(shared_status_memory_id, NULL, 0);
    
    //conversation protocol initiation
    int current_package_status = 0;

    while(current_stage!=Stage::Finished)
    {
        //get a single package from fingerprint
        Package current_package = extract_package();
        std::memcpy(message_box, &current_package, sizeof(Package));
        
        //protocol - sent logic
        current_package_status = (int)Package_Status::Sent;
        std::memcpy(protocol, &current_package_status,sizeof(int));
        std::cout<<"sent package: "<<std::endl;
        current_package.show();

        //await response
        while(*(static_cast<int*>(protocol))!=int(Package_Status::Recieved))
        {
            //do nothing i gues...
            std::cout<<"press any key"<<std::endl;
            std::cin.get();
            if(*(static_cast<int*>(protocol))!=int(Package_Status::Recieved))
                std::cout<<"no response from reciever yet"<<std::endl;
        }
    }

    delete message_box;
    delete protocol;
    return true;
}

Package Fingerprint_Emitter::extract_package()
{
    Package message;
    switch (current_stage)
    {
    case Stage::Control_Package:
        message = Package(std::to_string(m_data.get_size()),Package_Type::control);
        current_stage = Stage::Data_Package;
        break;

    case Stage::Data_Package:
        message = Package(m_data[current_id],Package_Type::data);
        current_id++;
        if(current_id == m_data.get_size())
            current_stage = Stage::Finished;
        break;

    default:
        break;
    }
    return message;
}