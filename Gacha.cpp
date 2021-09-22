#include "Gacha.hpp"

Item gacha()
{
    
    Item item = Item();

    return item;
}

void printGacha(Item item)
{
    std::cout << "You got:\n";
            
    switch (item.getRarity())
    {
    case RarityCommon:
        std::cout << ct::Mod(ct::CWhite) << item.getItemName() 
        << ct::Mod() << std::endl << std::endl;
        break;
    case RarityUncommon:
        std::cout << ct::Mod(ct::CGreen) << item.getItemName() 
        << ct::Mod() << std::endl << std::endl;
        break;
    case RarityRare:
        std::cout << ct::Mod(ct::CBlue) << item.getItemName() 
        << ct::Mod() << std::endl << std::endl;
        break;
    case RarityEpic:
        std::cout << ct::Mod(ct::CMagenta) << item.getItemName() 
        << ct::Mod() << std::endl << std::endl;
        break;
    case RarityLegendary:
        std::cout << ct::Mod(ct::CYellow) << item.getItemName() 
        << ct::Mod() << std::endl << std::endl;
        break;
    default:
        break;
    }

    return;
}