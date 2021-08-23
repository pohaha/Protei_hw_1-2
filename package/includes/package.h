#pragma once
#include <iostream>
#include <string>
#include <cstring>

#define BUFFER_SIZE 10

enum class Package_Status
{
    None,
    Sent,
    Recieved
};

std::string to_string(Package_Status);

enum class Package_Type
{
    None,
    Control,
    Data
};

std::string to_string(Package_Type current_type);

class Package
{
public:
    Package(const std::string &message, const Package_Type &type);
    Package() = default;

    Package(const Package &other);
    Package &operator=(const Package &other);
    ~Package() = default;

    Package_Type get_type();
    std::string get_data();
    Package_Status get_status();

    void show();
    void change_status(Package_Status new_status);

private:
    Package_Status m_status = Package_Status::None;
    Package_Type m_type = Package_Type::None;
    std::size_t m_size = 0;
    char m_buff[BUFFER_SIZE];
};