#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <random>

#include "ctools.hpp"
#include "gameplay.hpp"

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
            ct::Mod() << "\n(1): Gacha       (2): View Items  (3): Use Items" <<
            ct::Mod() << "\n(4): View Plant  (5): Minigame    (6): Exit Game"  <<
            ct::Mod() << "\n(7): MORE MONEY" <<
            ct::Mod() << "\nEnter input: ";

        int input = ct::getInt(1, 8);
        std::cout << '\n';

        switch (input)
        {
        // Gacha
        case 1:
            break;

        // Exit
        case 6:
            running = false;
            break;

        // Buy money
        case 7:
            gBuyMoney();
            break;
        
        default:
            break;
        }
    }

    return 0;
}