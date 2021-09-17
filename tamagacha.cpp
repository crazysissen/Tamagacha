#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

#include "Gacha.hpp"


int main()
{
    srand(time(NULL));

    std::vector<Item> playerItems;

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
        else if(a == 1)
        {
            Item tempItem = gacha();

            std::cout << "You got:\n";
            
            switch (tempItem.getRarity())
            {
            case RarityCommon:
                std::cout << ct::Mod(ct::CWhite) << tempItem.getItemName() 
                << ct::Mod() << std::endl << std::endl;
                break;
            case RarityUncommon:
                std::cout << ct::Mod(ct::CGreen) << tempItem.getItemName() 
                << ct::Mod() << std::endl << std::endl;
                break;
            case RarityRare:
                std::cout << ct::Mod(ct::CBlue) << tempItem.getItemName() 
                << ct::Mod() << std::endl << std::endl;
                break;
            case RarityEpic:
                std::cout << ct::Mod(ct::CMagenta) << tempItem.getItemName() 
                << ct::Mod() << std::endl << std::endl;
                break;
            case RarityLegendary:
                std::cout << ct::Mod(ct::CYellow) << tempItem.getItemName() 
                << ct::Mod() << std::endl << std::endl;
                break;
            default:
                break;
            }

            playerItems.push_back(tempItem);
        }
        else if(a == 2)
        {
            std::cout << ct::Mod(ct::CCyan) << "Items:\n" << ct::Mod();
            printItemVector(playerItems);
            std::cout << '\n';
        }

    }

    return 0;
}

