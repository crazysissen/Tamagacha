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
        //Insert game here
        std::cout << "=======================~~ TamaGacha ~~========================\n";
        std::cout << 
            ct::Mod() << "Healthiness: " << ct::Mod(ct::CGreen) << health <<
            ct::Mod() << "  Happiness: " << ct::Mod(ct::CMagenta) << happiness <<
            ct::Mod() << "  Hydration: " << ct::Mod(ct::CCyan) << hydration <<
            ct::Mod() << "  Nutrition: " << ct::Mod(ct::CRed) << nutrition << 
            ct::Mod() << "  Money: " << ct::Mod(ct::CYellow) << money << 

            ct::Mod() << "\n\nEnter input: ";

        int a = 0;
        std::cin >> a;

        std::cout << '\n';
            
        if (a == 0)
        {
            running = false;
        }
    }

    return 0;
}

Item gacha()
{
    
    Item item();

    return item;
}
