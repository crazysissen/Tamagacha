#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <random>


#include "ctools.hpp"

int main()
{
    srand(time(NULL));

    bool running  = true;
    std::string a = "";

    std::cin >> a;

    ct::color(ct::CBlue);
    std::cout << a;

    ct::color(ct::CBlue, ct::CBlack, ct::CSBold);
    std::cout << a << '\n';

    ct::color(ct::CWhite, ct::CBlack, ct::CSReset);
    
    while(running)
    {
        //Game here
    }

    return 0;
}