#ifndef ITEM
#define ITEM

#include<random>
#include<iostream>

#include "ctools.hpp"

enum ItemType
{
    ItemTypeFood,
    ItemTypeToy,
    ItemTypeWater,
    ItemTypeFertilizer,
    ItemTypeTreasure,

    ItemTypeCount // <-- Keep Last
};

enum Rarity
{
    RarityCommon,
    RarityUncommon,
    RarityRare,
    RarityEpic,
    RarityLegendary,

    RarityCount // <-- Keep Last

};

class Item

{
public:
    Item();
    Item(int happinessChange, int hydrationChange, int nutritionChange, int healthChange);
    ~Item() = default;
    ItemType getItemType();
    Rarity getRarity();
    int getHappinessChange();
    int getHydrationChange();
    int getNutritionChange();
    int getHealthChange();
    int getMoneyChange();
    std::string getItemName();

    void setHappinessChange(int stat);
    void setHydrationChange(int stat);
    void setNutritionChange(int stat);
    void setHealthChange(int stat);
    void setMoneyChange(int stat);
    void setItemName(std::string name);


    std::string formatItemName(ItemType itemType, Rarity rarity);

private:
    void setStats(ItemType itemType, Rarity rarity);


private:
    ItemType m_itemType;
    Rarity m_rarity;
    int m_happinessChange;
    int m_hydrationChange;
    int m_nutritionChange;
    int m_healthChange;
    int m_moneyChange;

    std::string m_itemName;
};

void printItemArray(std::vector<Item> itemArray[]);

#endif //ITEM