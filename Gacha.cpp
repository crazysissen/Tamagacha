#include <fstream>
#include <sstream>

#include "Gacha.hpp"

Item gacha()
{
    
    Item item = Item();

    animateGacha(item);

    return item;
}


void animateGacha(Item item)
{
    std::string tempString;
    std::stringstream chestOpen;
    std::stringstream chestClosed;

    std::ifstream f ("images/chestOpen.txt");
    while(getline(f, tempString))
    {
        chestOpen << tempString << "\n";
    }

    f.close();

    

    f.open("images/chestClosed.txt");

    while(getline(f, tempString))
    {
        chestClosed << tempString << "\n";
    }
    
    f.close();

    std::cout << chestClosed.str() << "\n";

}


void printGacha(Item item)
{
    std::cout << "You got:\n";
            
    std::cout << ct::Mod(gachaColor(item)) << item.getItemName() 
    << ct::Mod() << std::endl << std::endl;

    return;
}

ct::Color gachaColor(Item item)
{
    switch (item.getRarity())
    {
    case RarityCommon:
        return ct::CWhite;

    case RarityUncommon:
        return ct::CGreen;

    case RarityRare:
        return ct::CBlue;

    case RarityEpic:
        return ct::CMagenta;

    case RarityLegendary:
        return ct::CYellow;
        
    default:
        return ct::CWhite;
    }
}