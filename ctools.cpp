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

int ct::getInt()
{
    std::string buffer;

    while(true)
    {
        std::cin >> buffer;

        try
        {
            int value = std::stoi(buffer);
            return value;
        }
        catch(const std::exception& e)
        {
            std::cout << "Invalid. Try again: ";
        }
    }
}

int ct::getInt(int min, int max)
{
    while (true)
    {
        int value = getInt();

        if (value >= min && value < max)
        {
            return value;
        }
        
        std::cout << "Out of range. Try again: ";
    }
}

ct::Mod::Mod(Color foreground, Color background, ColorSetting setting)
    :
    m_foreground(foreground),
    m_background(background),
    m_setting(setting)
{
}