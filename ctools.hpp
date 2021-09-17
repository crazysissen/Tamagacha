#include <string>

namespace ct
{

    enum Color
    {
        ColorBlack = 30,
        ColorRed,
        ColorGreen,
        ColorYellow,
        ColorBlue,
        ColorMagenta,
        ColorCyan,
        ColorWhite
    };

    void color(Color foreground = ColorWhite, Color background = ColorBlack, );

}