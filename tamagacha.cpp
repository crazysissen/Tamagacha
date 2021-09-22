#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <random>

#include "Item.hpp"
#include "ctools.hpp"

int main()
{
    srand(time(NULL));

    int health      = 100;
    int happiness   = 50;
    int hydration   = 100;
    int nutrition   = 20;
    int money = 10;

    bool running = true;
    while(running)
    {
<<<<<<< HEAD
        std::cout << "=========================== TamaGacha ============================\n";
=======
        //Insert game here
        std::cout << "=======================~~ TamaGacha ~~========================\n";
>>>>>>> aa14507fe4dbe411e0b2e006eedec15d27ad2ad9
        std::cout << 
            ct::Mod() << "Healthiness: " << ct::Mod(ct::CGreen) << health <<
            ct::Mod() << "  Happiness: " << ct::Mod(ct::CMagenta) << happiness <<
            ct::Mod() << "  Hydration: " << ct::Mod(ct::CCyan) << hydration <<
            ct::Mod() << "  Nutrition: " << ct::Mod(ct::CRed) << nutrition << 
            ct::Mod() << "  Money: " << ct::Mod(ct::CYellow) << money << 

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

Item gacha()
{
    

    Item item();

    return item;
}
