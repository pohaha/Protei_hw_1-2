#include <fingerprint.h>


bool Fingerprint::parse_from_file(const char* fingerprint_file_path)
{
    std::cout<<"parsing fingerprint file at "<<fingerprint_file_path<<std::endl;
    std::ifstream fingerprint_file;
    std::string full_fingerprint;
    fingerprint_file.open (fingerprint_file_path);
    if(!fingerprint_file.is_open())
    {
        //TODO error handling
        std::cout<<"error opening \""<<fingerprint_file_path<<"\""<<std::endl;
        return m_valid = false;
    }
    getline(fingerprint_file,full_fingerprint);
    fingerprint_file.close();
    return parse_from_string(full_fingerprint);
}

bool Fingerprint::parse_from_string(std::string parsed_string)
{    
    std::cout<<"started parsing fingerprint from string"<<std::endl;

    parsed_string = normalize_string(parsed_string);

    std::stringstream split_stream(parsed_string);
    std::string element;
    while(std::getline(split_stream,element,':'))
    {
        m_valid = true;
        std::string* new_values = new std::string[m_size+1];
        for(unsigned int i=0;i<m_size;i++)
            new_values[i] = m_values[i];
        delete[] m_values;
        new_values[m_size] = element;
        
        //codereview #6
        ++m_size;
        m_values = new_values;
    }

    if(m_valid)
        std::cout<<"fingerprint generation successfull"<<std::endl;
    else
        std::cout<<"ERROR occured during parcing fingerprint from string"<<std::endl;
    return m_valid;
}


void Fingerprint::show()
{
    if(not m_valid)
    {
        std::cout<<"fingerprint currently invalid"<<std::endl;
        return;
    }
    for(unsigned int i = 0; i < m_size; i++)
    {
        std::cout<<m_values[i];
        if(i != m_size-1) 
            std::cout<<":";
    }
    std::cout<<std::endl;
}

unsigned int Fingerprint::get_size()
{
    return m_size;
}

bool Fingerprint::is_valid() const
{
    return m_valid;
}


const std::string& Fingerprint::operator[](std::size_t id)
{
    if (not m_valid)
    {
        show();
        return std::string();
    }    
    if(id >= m_size)
    {
        std::cout<<"out of bounds error"<<std::endl;
        return (std::string("ERROR"));
    }
    return m_values[id];
}


Fingerprint::Fingerprint(const Fingerprint& other)
{
    if (not other.is_valid())
    {
        std::cout<<"target is invalid"<<std::endl;
        m_valid = false;
        return;
    }
    m_size = other.m_size;
    m_values = new std::string[m_size];
    for(unsigned int i=0;i<m_size;i++)
        m_values[i] = other.m_values[i];
    m_valid = true;
}

Fingerprint& Fingerprint::operator= (const Fingerprint& other)
{
    if (not other.is_valid())
    {
        std::cout<<"target is invalid"<<std::endl;
        m_valid = false;
        return *this;
    }
    if (this!=(&other))
    {
        m_size = other.m_size;
        m_values = new std::string[m_size];
        for(unsigned int i=0;i<m_size;i++)
            m_values[i] = other.m_values[i];
        m_valid = true;
    }
    return *this;
}

Fingerprint::~Fingerprint()
{
    delete[] m_values;
}


std::string Fingerprint::normalize_string(std::string fingerprint_with_trash)
{
    std::string normalized_string = fingerprint_with_trash;
    std::size_t trash_delimetr = fingerprint_with_trash.find('=');
    if(trash_delimetr!=std::string::npos)
    {
        std::cout<<"removing trash: "<<fingerprint_with_trash.substr(0,trash_delimetr+1)<<std::endl;
        normalized_string = fingerprint_with_trash.substr(trash_delimetr+1);
    }

    return normalized_string;
}



