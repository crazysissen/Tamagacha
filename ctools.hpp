#include <string>

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

}