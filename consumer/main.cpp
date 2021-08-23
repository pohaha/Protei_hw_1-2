#include <package.h>
#include <fingerprint.h>

#include <iostream>
#include <string>
#include <sys/shm.h>

int main()
{
    Fingerprint test_fingerprint;
    test_fingerprint.parse_from_file("../../../consumer/test_digest.txt");
    std::cout << std::endl;

    //create shared memory - aquire it's id
    int shared_package_id;
    shared_package_id = shmget(key_t(9877), sizeof(Package), 0666); //note to self - 0666 is wierd AF bitmask - do not touch
    if (shared_package_id < 0)
    {
        //TODO error handling
        std::cout << "shmget memory aquisition error" << std::endl;
        return 1;
    }

    //project shared memory in the scope of the function
    void *shared_package;
    shared_package = shmat(shared_package_id, NULL, 0);

    //await message transfer initiation via control package
    while (static_cast<Package *>(shared_package)->get_type() !=
           Package_Type::Control)
    {
        //wait i guess
        std::cout << "no invitation yet. Press enter to refresh" << std::endl;
        std::cin.get();
    }
    std::cout << "recieved control package" << std::endl;

    //basic data agregation (ie fingerprint size for main recieve loop)
    unsigned int data_packages_total = std::stoi(static_cast<Package *>(shared_package)->get_data());
    std::cout << "Packages total: " << data_packages_total << std::endl;
    std::cout << std::endl;

    //send reply
    static_cast<Package *>(shared_package)->change_status(Package_Status::Recieved);

    //recieve and compare data packages
    Package current_package;
    std::cout << "started recieving data packages" << std::endl;
    for (int i = 0; i < data_packages_total; i++)
    {
        //await new package
        while (static_cast<Package *>(shared_package)->get_status() !=
               Package_Status::Sent)
        {
            //do nothing i gues...
            std::cout << "no packages recieved yet, press enter to refresh" << std::endl;
            std::cin.get();
        }
        std::memcpy(&current_package, shared_package, sizeof(Package));
        std::cout << "From shared memory: " << current_package.get_data() << std::endl;
        std::cout << "From terminal output: " << test_fingerprint[i] << std::endl;

        //send reply
        static_cast<Package *>(shared_package)->change_status(Package_Status::Recieved);
    }
}