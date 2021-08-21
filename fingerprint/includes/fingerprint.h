#pragma once

#include<string>
#include<iostream>
#include<sstream>
#include <package.h>

class Fingerprint
{
    public:
        Fingerprint(const char* fingerprint_file_path);
        Fingerprint(std::string string_fingerprint);

        void show();
        bool split_in_packages(Package& placeholder);


        Fingerprint() = default;
        Fingerprint(const Fingerprint& other);
        Fingerprint& operator= (const Fingerprint& other);
        ~Fingerprint();
    private:
        Package generate_package(const std::string& type, int id = 0);
        std::string* m_values = nullptr;
        unsigned int m_size = 0;
        void parse_from_string(std::string full_fingerprint);
};