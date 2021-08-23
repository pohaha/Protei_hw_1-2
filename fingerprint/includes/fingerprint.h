#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>

#include <package.h>


class Fingerprint
{
    public:
        void show();
        unsigned int get_size();

        //code review # 4.3
        bool parse_from_string(std::string full_fingerprint);
        bool parse_from_file(const char* fingerprint_file_path);
        bool is_valid() const;

        const std::string& operator[](std::size_t id);

        Fingerprint() = default;
        Fingerprint(const Fingerprint& other);
        Fingerprint& operator= (const Fingerprint& other);
        ~Fingerprint();
        
    private:
        bool m_valid = false;
        std::string* m_values = nullptr;
        unsigned int m_size = 0;

        //code review #8
        std::string normalize_string(std::string fingerprint_with_trash);
};