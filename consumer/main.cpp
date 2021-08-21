#include <iostream>
#include <string>
#include <package.h>

int main()
{
    Package Sender(std::string("Hello"));
    Package Reciever;

    std::cout<<"Before transaction:"<<std::endl;

    std::cout<<"Package Sender: ";
    Sender.show();
    std::cout<<"Package Reciever: ";
    Reciever.show();

    char mailbox[10];
    Sender.export_content(mailbox);
    Reciever.import_content(mailbox);

    std::cout<<"After transaction:"<<std::endl;

    std::cout<<"Package Sender: ";
    Sender.show();
    std::cout<<"Package Reciever: ";
    Reciever.show();
}