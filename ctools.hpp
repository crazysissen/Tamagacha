#pragma once

#include <string>
#include <ostream>
#include <vector>

namespace ct
{

    enum Color
    {
        CBlack = 30,
        CRed,
        CGreen,
        CYellow,
        CBlue,
        CMagenta,
        CCyan,
        CWhite
    };

    enum ColorSetting
    {
        CSNone = -1,
        CSReset = 0,
        CSBold = 1,
        CSUnderline = 4
    };

    void color(Color foreground = CWhite, Color background = CBlack, ColorSetting setting = CSNone);
    void colorReset();
    char getChar();
    int getInt();
    int getInt(int min, int max);

    class Mod
    {
    private:
        Color m_foreground;
        Color m_background;
        ColorSetting m_setting;

    public:
        Mod(Color foreground = CWhite, Color background = CBlack, ColorSetting setting = CSNone);



        friend std::ostream& operator<<(std::ostream& os, const Mod& mod)
        {
            ct::color(mod.m_foreground, mod.m_background, mod.m_setting);
            return os;
        }
    };

}