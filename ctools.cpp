#include "ctools.hpp"

#include <iostream>
#include <sstream>



void ct::color(Color foreground, Color background, ColorSetting setting)
{
    std::cout << "\033[" << foreground << ';' << background + 10; 

    if (setting != CSNone)
    {
        std::cout << ";";
        std::cout << setting;
    }

    std::cout << 'm';
}