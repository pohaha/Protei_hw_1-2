#include <package.h>
#include <fingerprint.h>

#include <iostream>
#include <string>
#include <sys/shm.h>


int main()
{
    Fingerprint test_fingerprint;
    test_fingerprint.parse_from_file("../../../consumer/test_digest.txt");
    std::cout<<std::endl;
    //create shared memory - aquire it's id
    int shared_status_memory_id;
    int shared_package_id;
        //note to self - 0666 is wierd AF bitmask - do not touch
    shared_package_id = shmget(key_t(9877), sizeof(Package), 0666);
    shared_status_memory_id = shmget(key_t(9876), sizeof(int), 0666);
    if((shared_status_memory_id < 0) ||  //or
       (shared_package_id < 0))
    {   
        //TODO error handling
        std::cout<<"shmget memory aquisition error"<<std::endl;
        return 1;
    }

    //project shared memory in the scope of the function
    void* message_box;
    void* protocol;
    message_box = shmat(shared_package_id, NULL, 0);
    protocol = shmat(shared_status_memory_id, NULL, 0);
    
    //conversation protocol initiation
    int current_package_status = 0;
   
    //await message transfer initiation via control package
    while((static_cast<Package*>(message_box))->get_type() !=
           Package_Type::control)
    {
        //wait i guess
        std::cout<<"no messages yet. Press enter to refresh"<<std::endl;
        std::cin.get();
    }
    std::cout<<"recieved control package"<<std::endl;
    //basic data agregation (ie fingerprint size for main recieve loop)
    std::string package_content = static_cast<Package*>(message_box)->get_data();
    unsigned int data_packages_total = std::stoi(package_content);
    std::cout<<"Packages total: "<<data_packages_total<<std::endl;
    std::cout<<std::endl;
    //send reply
    current_package_status = int(Package_Status::Recieved);
    std::memcpy(protocol,&current_package_status,sizeof(int));

    //recieve and compare data packages
    Package current_package;
    std::cout<<"started recieving data packages"<<std::endl;
    for(int i = 0; i<data_packages_total; i++)
    {
        //await invitation
        while(*(static_cast<int*>(protocol)) !=
              int(Package_Status::Sent))
        {
            //do nothing i gues...
            std::cout<<"no packages recieved yet, press enter to refresh"<<std::endl;
            std::cin.get();
        }
        std::memcpy(&current_package,message_box,sizeof(Package));
        std::cout<<"From shared memory: "<<current_package.get_data()<<std::endl;
        std::cout<<"From terminal output: "<<test_fingerprint[i]<<std::endl;

        //send reply
        current_package_status = int(Package_Status::Recieved);
        std::memcpy(protocol,&current_package_status,sizeof(int));
    }
}