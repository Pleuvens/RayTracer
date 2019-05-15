#include <iostream>

#include "input/svati_parser.hh"

int main()
{
    SvatiParser parser = SvatiParser("../C-sources/tests/cube.svati");
    
    std::cout << "Parsing..." << std::endl;  

    Scene s = parser.parse();

    std::cout << "Processing" << std::endl;

    s.setScene();

    std::cout << "Done." << std::endl;

    return 0;
}
