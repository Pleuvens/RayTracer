#pragma once

#include "parser.hh"

class SvatiParser : public Parser
{
    public:
        SvatiParser();
        SvatiParser(std::string filename_);

        Scene parse() override;
    
    private:
        void parseCamera(Scene& scene);
        void parseLight(Scene& scene);
        void parsePrimitive(Scene& scene);
};