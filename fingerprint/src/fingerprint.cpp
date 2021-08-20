#pragma once
#include <fingerprint.h>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include <fstream>

Fingerprint::Fingerprint(const char* fingerprint_file_path)
{
    std::cout<<"parsing file at "<<fingerprint_file_path<<std::endl;
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
    std::cout<<"parsing successfull"<<std::endl;
}

Fingerprint::Fingerprint(std::string string_fingerprint)
{
    parse_from_string(string_fingerprint);
}

Fingerprint::Fingerprint()
{
    
}

void Fingerprint::parse_from_string(std::string full_fingerprint)
{    
    char* full_fingerprint_as_cstring = (char *)(full_fingerprint.c_str());
    char* trash_part;
    char* real_part = full_fingerprint_as_cstring;
    trash_part = strtok(full_fingerprint_as_cstring,"=");
    if (trash_part!=NULL)
    {
        real_part=strtok(NULL,"=");
        std::cout<<"trash detected: "<<trash_part<<std::endl;
    }
    char* element;
    element = strtok(real_part,":");
    while(element!=NULL)
    {
        std::string* new_values = new std::string[size+1];
        for(unsigned int i = 0; i < size; i++)
            new_values[i] = m_values[i];
        delete[] m_values;
        size+=1;
        m_values = new_values;
        m_values[size-1] = element;
        element = strtok(NULL,":");
    }    
}

void Fingerprint::show()
{
    for(unsigned int i = 0; i < size; i++)
    {
        std::cout<<m_values[i];
        if(i != size-1) std::cout<<":";
    }
    std::cout<<std::endl;
}

Fingerprint::~Fingerprint()
{
    delete[] m_values;
}