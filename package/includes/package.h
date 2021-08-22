#pragma once
#include <iostream>
#include <string>
#include <cstring>
#define BUFFER_SIZE 10

enum class Package_Type
{
    none,
    control,
    data
};


class Package
{
public:
    Package(const std::string& message, const Package_Type& type);
    Package() = default;

    Package(const Package& other);
    Package& operator=(const Package& other);
    ~Package() = default;
    
    void show();


private:
    Package_Type m_type = Package_Type::none;
    std::size_t m_size = 0;
    char m_buff[BUFFER_SIZE];
};