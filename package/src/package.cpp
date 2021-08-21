#pragma once
#include <package.h>

#define BUFFER_SIZE 10

Package::Package(const std::string& message)
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

void Package::show()
{
    std::cout<<"Status: "<<int(m_status)<<std::endl;
    std::cout<<"Content: "<<m_buff<<std::endl;
}

void Package::set_status(const Package_Status& new_status)
{
    m_status = new_status;
}

void Package::export_content(void* mailbox)
{
    std::memcpy(mailbox, m_buff, sizeof(char)*BUFFER_SIZE);
    set_status(Package_Status::Sent);
}

void Package::import_content(void* mailbox)
{
    std::memcpy(m_buff, mailbox,sizeof(char)*BUFFER_SIZE);
    set_status(Package_Status::Recieved);
}



