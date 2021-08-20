#pragma once

#include<string>
#include<iostream>
#include<sstream>

class Fingerprint
{
    public:
        Fingerprint(const char* fingerprint_file_path);
        explicit Fingerprint(std::string string_fingerprint);
        Fingerprint();
        ~Fingerprint();
        void show();
    private:
        std::string* m_values = nullptr;
        unsigned int size = 0;
        void parse_from_string(std::string full_fingerprint);
};