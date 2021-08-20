#pragma once
#include <fingerprint.h>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include <fstream>

Fingerprint::Fingerprint(const char* fingerprint_file_path)
{
    std::cout<<"parsing fingerprint file at "<<fingerprint_file_path<<std::endl;
    std::ifstream fingerprint_file;
    std::string full_fingerprint;
    fingerprint_file.open (fingerprint_file_path);
    if(!fingerprint_file.is_open())
    {
        //TODO error handling
        std::cout<<"error opening \""<<fingerprint_file_path<<"\""<<std::endl;
        return;        
    }
    getline(fingerprint_file,full_fingerprint);
    fingerprint_file.close();
    parse_from_string(full_fingerprint);
    std::cout<<"parsing fingerprint file successfull"<<std::endl;
}

Fingerprint::Fingerprint(std::string string_fingerprint)
{
    parse_from_string(string_fingerprint);
}

Fingerprint::Fingerprint()
{
    
}

Fingerprint& Fingerprint::operator= (const Fingerprint& other)
{
    if (this!=(&other))
    {
        m_size = other.m_size;
        m_values = new std::string[m_size];
        for(unsigned int i=0;i<m_size;i++)
            m_values[i] = other.m_values[i];
    }
    return *this;
}

Fingerprint::Fingerprint(const Fingerprint& other)
{
    m_size = other.m_size;
    m_values = new std::string[m_size];
    for(unsigned int i=0;i<m_size;i++)
        m_values[i] = other.m_values[i];
}

void Fingerprint::parse_from_string(std::string parsed_string)
{    
    std::cout<<"started parsing fingerprint from string"<<std::endl;
    std::size_t trash_delimetr = parsed_string.find('=');
    if(trash_delimetr!=std::string::npos)
    {
        std::cout<<"removing trash: "<<parsed_string.substr(0,trash_delimetr+1)<<std::endl;
        parsed_string = parsed_string.substr(trash_delimetr+1);
    }    
    std::stringstream split_stream(parsed_string);
    std::string element;
    while(std::getline(split_stream,element,':'))
    {
        std::string* new_values = new std::string[m_size+1];
        for(unsigned int i=0;i<m_size;i++)
            new_values[i] = m_values[i];
        delete[] m_values;
        new_values[m_size] = element;
        m_size++;
        m_values = new_values;
    }
    std::cout<<"parsed fingerprint from string successfully"<<std::endl;
}

void Fingerprint::show()
{
    for(unsigned int i = 0; i < m_size; i++)
    {
        std::cout<<m_values[i];
        if(i != m_size-1) std::cout<<":";
    }
    std::cout<<std::endl;
}

Fingerprint::~Fingerprint()
{
    delete[] m_values;
}