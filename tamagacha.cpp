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

    int health      = 100;
    int happiness   = 50;
    int hydration   = 100;
    int nutrition   = 20;

    bool running = true;
    while(running)
    {
        std::cout << "=========================== TamaGacha ============================\n";
        std::cout << 
            ct::Mod() << "Healthiness: " << ct::Mod(ct::CGreen) << health <<
            ct::Mod() << "  Happiness: " << ct::Mod(ct::CYellow) << happiness <<
            ct::Mod() << "  Hydration: " << ct::Mod(ct::CCyan) << hydration <<
            ct::Mod() << "  Nutrition: " << ct::Mod(ct::CRed) << nutrition << 
            ct::Mod() << "\n\nEnter input: ";

        int input = ct::getInt(0, 10);
        std::cout << '\n';

        if (input == 0)
        {
            running = false;
        }
        else
        {
            switch (input)
            {
            case 0:
                
                break;
            
            default:
                break;
            }
        }
    }

    return 0;
}