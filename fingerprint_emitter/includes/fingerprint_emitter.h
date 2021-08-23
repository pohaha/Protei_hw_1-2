#pragma once

#include <fingerprint.h>
#include <package.h>

#include <string>
#include <iostream>
#include <sys/shm.h>


enum class Stage
{
    None,
    Control_Package,
    Data_Package,
    Finished
};

class Fingerprint_Emitter
{
    public:
        Fingerprint_Emitter(const Fingerprint& data);
        
        bool send();
        Package extract_package();

    private:
        Stage current_stage = Stage::None;
        Fingerprint m_data;
        std::size_t current_id = 0;

};
