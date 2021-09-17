#include <iostream>
#include <string>

#include "ctools.hpp"

int main()
{
    std::string a = "";

    std::cout << "Hello Sixten boi\n";
    std::cin >> a;

    ct::color(ct::CBlue);
    std::cout << a;

    ct::color(ct::CBlue, ct::CBlack, ct::CSBold);
    std::cout << a << '\n';

    ct::color(ct::CWhite, ct::CBlack, ct::CSReset);

    return 0;
}