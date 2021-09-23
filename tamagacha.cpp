#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

#include "ctools.hpp"
#include "gameplay.hpp"

#include "Item.hpp"
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
        std::cout << "=========================== TamaGacha ============================\n";
        std::cout << 
            ct::Mod() << "Healthiness: " << ct::Mod(ct::CGreen) << health <<
            ct::Mod() << "  Happiness: " << ct::Mod(ct::CYellow) << happiness <<
            ct::Mod() << "  Hydration: " << ct::Mod(ct::CCyan) << hydration <<
            ct::Mod() << "  Nutrition: " << ct::Mod(ct::CRed) << nutrition << 
            ct::Mod() << "  Money: " << ct::Mod(ct::CYellow) << money << 
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
            break;

        case 2:
            std::cout  << ct::Mod(ct::CCyan) << "Items:\n" << ct::Mod();
            printItemArray(playerItems);
            std::cout << '\n';
            break;

        case 3:
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
            break;

        case 4:
            break;

        case 5:
            gMinigame();
            break;

        // Exit
        case 6:
            running = false;
            break;

        case 7:
            gBuyMoney();
            money += 10;
            break;

        default:
            break;
        }



    }

    return 0;
}

