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
        if(health > 100)
        {
            health = 100;
        }
        if(happiness > 100)
        {
            happiness = 100;
        }
        if(hydration > 100)
        {
            hydration = 100;
        }
        if(nutrition > 100)
        {
            nutrition = 100;
        }
        
        //Insert game here
        std::cout << "=======================~~ TamaGacha ~~========================\n";
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
        else if(input == 1)
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
        else if(input == 2)
        {
            std::cout  << ct::Mod(ct::CCyan) << "Items:\n" << ct::Mod();
            printItemArray(playerItems);
            std::cout << '\n';
        }
        else if(input == 3)
        {
            bool validInput = false;
            std::cout << "Which item would you like to use?\n";

            while(!validInput)
            {
                printItemArray(playerItems);
                input = ct::getInt(0, (ItemTypeCount - 1) * RarityCount);

                if(!playerItems[input].empty())
                {
                    health += playerItems[input][0].getHealthChange();
                    happiness += playerItems[input][0].getHappinessChange();
                    hydration += playerItems[input][0].getHydrationChange();
                    nutrition += playerItems[input][0].getNutritionChange();

                    std::cout << "\nUsed one " << playerItems[input][0].getItemName() << "\n\n";

                    playerItems[input].pop_back();
                    validInput = true;
                }
                else
                {
                    std::cout << ct::Mod(ct::CRed) 
                    << "\nInvalid input, please try again\n" << ct::Mod();
                }
            }   
        }

    }

    return 0;
}

