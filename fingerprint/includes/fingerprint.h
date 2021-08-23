#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>

#include <package.h>


class Fingerprint
{
    public:
        Fingerprint(const char* fingerprint_file_path);
        Fingerprint(std::string string_fingerprint);

        void show();
        unsigned int get_size();

        const std::string& operator[](std::size_t id);

        Fingerprint() = default;
        Fingerprint(const Fingerprint& other);
        Fingerprint& operator= (const Fingerprint& other);
        ~Fingerprint();
        
    private:
        std::string* m_values = nullptr;
        unsigned int m_size = 0;
        void parse_from_string(std::string full_fingerprint);
};