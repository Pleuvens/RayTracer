#pragma once

#include <string>
#include <fstream>
#include "../scene/scene.hh"

class Parser
{
    public:
        Parser();
        Parser(std::string filename_);

        std::string getFilename() const;
        void setFilename(std::string filename_);

        virtual Scene parse() = 0;
    protected:
        std::string filename;
        std::ifstream infile;     
};