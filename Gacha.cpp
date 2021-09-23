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
    std::wstring tempString;
    std::wifstream f ("images/chestOpen.txt");

    std::wstringstream chestOpen;
    chestOpen << f.rdbuf();
    f.close();

    
    std::wstringstream chestClosed;

    f.open("images/chestClosed.txt");

    while(getline(f, tempString))
    {
        chestClosed << tempString << "\n";
    }
    
    f.close();

    std::wcout << chestClosed.str() << "\n";

    std::wofstream f2("images/test.txt");
    f2 << chestOpen.str();

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