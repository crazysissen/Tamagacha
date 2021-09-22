#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

#include "Gacha.hpp"


int main()
{
    srand(time(NULL));

    std::vector<Item> playerItems[(ItemTypeCount - 1) * RarityCount];

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
            if(money > 0)
            {
                money--;

                Item tempItem = gacha();

                if(tempItem.getItemType() == ItemTypeTreasure)
                {
                    std::cout << "You got:\n";
                    std::cout << ct::Mod(ct::CYellow) << 2 * ((int)tempItem.getRarity() + 1) << " gold\n\n" << ct::Mod();
                    money += 2 * ((int)tempItem.getRarity() + 1);
                }
                else
                {
                    printGacha(tempItem);
                    playerItems[tempItem.getItemType() * RarityCount + tempItem.getRarity()].push_back(tempItem);
                }
            }
            else
            {
                std::cout << ct::Mod(ct::CRed) << "You have no money\n\n" << ct::Mod();
            }
        }
        else if(a == 2)
        {
            std::cout  << ct::Mod(ct::CCyan) << "Items:\n" << ct::Mod();
            printItemArray(playerItems);
            std::cout << '\n';
        }

    }

    return 0;
}

