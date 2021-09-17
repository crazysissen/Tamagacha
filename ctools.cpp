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

void ct::colorReset()
{
    color(CWhite, CBlack, CSReset);
}

char ct::getChar()
{
    char c = 'A';
    std::cin.get(c);

    return c;
}

ct::Mod::Mod(Color foreground, Color background, ColorSetting setting)
    :
    m_foreground(foreground),
    m_background(background),
    m_setting(setting)
{
}