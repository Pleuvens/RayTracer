#include "parser.hh"

Parser::Parser(std::string filename_)
{
    filename = filename_;
}

std::string Parser::getFilename() const
{
    return filename;
}

void Parser::setFilename(std::string filename_)
{
    filename = filename_;
}