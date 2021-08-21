#pragma once
#include <iostream>
#include <string>
#include <cstring>

#define BUFFER_SIZE 10
enum class Package_Status
{
    Sent,
    Recieved,
    Untouched
};

//std::ostream& operator<< (std::ostream& os, const Package_Status& status)

class Package
{
public:
    Package(const std::string& message);
    Package() = default;
    void set_status(const Package_Status& new_status);
    void show();
    void export_content(void* mailbox);
    void import_content(void* mailbox);
private:
    std::size_t m_size = 0;
    Package_Status m_status = Package_Status::Untouched;
    char m_buff[BUFFER_SIZE];
};