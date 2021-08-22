#include <package.h>

#define BUFFER_SIZE 10

Package::Package(const std::string& message, const Package_Type& type):
    m_type(type)
{
    if(message.length()>=BUFFER_SIZE)
    {
        std::cout<<"buffer overflow"<<std::endl;
        return;
    }
    m_size = message.length();
    for(unsigned int i=0; i<m_size;i++)
        m_buff[i] = message[i];
    m_buff[m_size] = '\0';   
}


Package::Package(const Package& other):
    m_type(other.m_type),
    m_size(other.m_size)
{
    std::memcpy(m_buff,other.m_buff,sizeof(char)*BUFFER_SIZE);
}

Package& Package::operator=(const Package& other)
{
    if (this!=&other)
    {
        m_type = other.m_type;
        m_size = other.m_size;
        std::memcpy(m_buff,other.m_buff,sizeof(char)*BUFFER_SIZE);
    }
    return *this;
}


void Package::show()
{
    std::cout<<"Package type: "<<int(m_type)<<std::endl;
    std::cout<<"Content: "<<m_buff<<std::endl;
}



