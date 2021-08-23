#include <package.h>

#define BUFFER_SIZE 10

std::string to_string(Package_Type current_type)
{
    std::string type_as_string;
    switch (current_type)
    {
    case Package_Type::Control:
        type_as_string = "Control package";
        break;
    case Package_Type::Data:
        type_as_string = "Data package";
        break;
    case Package_Type::None:
        type_as_string = "Undefined package";
        break;

    default:
        type_as_string = "ERROR converting type to string";
        break;
    }
    return type_as_string;
}

std::string to_string(Package_Status current_status)
{
    std::string status_as_string;
    switch (current_status)
    {
    case Package_Status::None:
        status_as_string = "None";
        break;
    case Package_Status::Recieved:
        status_as_string = "Recieved";
        break;
    case Package_Status::Sent:
        status_as_string = "Sent";
        break;

    default:
        status_as_string = "ERROR converting status to string";
        break;
    }
    return status_as_string;
}

Package::Package(const std::string &message, const Package_Type &type) : m_type(type)
{
    if (message.length() >= BUFFER_SIZE)
    {
        std::cout << "buffer overflow" << std::endl;
        return;
    }
    m_size = message.length();
    for (unsigned int i = 0; i < m_size; i++)
        m_buff[i] = message[i];
    m_buff[m_size] = '\0';
}

Package::Package(const Package &other) : m_status(other.m_status),
                                         m_type(other.m_type),
                                         m_size(other.m_size)
{
    std::memcpy(m_buff, other.m_buff, sizeof(char) * BUFFER_SIZE);
}

Package &Package::operator=(const Package &other)
{
    if (this != &other)
    {
        m_type = other.m_type;
        m_size = other.m_size;
        m_status = other.m_status;
        std::memcpy(m_buff, other.m_buff, sizeof(char) * BUFFER_SIZE);
    }
    return *this;
}

void Package::show()
{
    std::cout << "Package type: " << to_string(m_type) << std::endl;
    std::cout << "Package status: " << to_string(m_status) << std::endl;
    std::cout << "Content: " << m_buff << std::endl;
}

Package_Type Package::get_type()
{
    return m_type;
}

std::string Package::get_data()
{
    return std::string(m_buff);
}

void Package::change_status(Package_Status new_status)
{
    m_status = new_status;
}

Package_Status Package::get_status()
{
    return m_status;
}