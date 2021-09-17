#include "Item.hpp"

Item::Item()
{
    m_itemType = static_cast<ItemType>(rand() % 5);
    m_rarity = static_cast<Rarity>(rand() % 5);

    setItemName(formatItemName(m_itemType, m_rarity));

    setStats(m_itemType, m_rarity);
}

Item::Item(int happinessChange, int hydrationChange, int nutritionChange, int healthChange)
:
m_happinessChange(happinessChange),
m_hydrationChange(hydrationChange),
m_nutritionChange(nutritionChange),
m_healthChange(healthChange)
{}

ItemType Item::getItemType()
{
    return m_itemType;
}

Rarity Item::getRarity()
{
    return m_rarity;
}

int Item::getHappinessChange()
{
    return m_happinessChange;
}

int Item::getHydrationChange()
{
    return m_hydrationChange;
}

int Item::getNutritionChange()
{
    return m_nutritionChange;
}

int Item::getHealthChange()
{
    return m_healthChange;
}

int Item::getMoneyChange()
{
    return m_moneyChange;
}

std::string Item::getItemName()
{
    return m_itemName;
}

void Item::setHappinessChange(int stat)
{
    m_happinessChange = stat;
}

void Item::setHydrationChange(int stat)
{
    m_hydrationChange = stat;
}

void Item::setNutritionChange(int stat)
{
    m_nutritionChange = stat;
}

void Item::setHealthChange(int stat)
{
    m_healthChange = stat;
}

void Item::setMoneyChange(int stat)
{
    m_moneyChange = stat;
}

void Item::setItemName(std::string name)
{
    m_itemName = name;
}


std::string Item::formatItemName(ItemType itemType, Rarity rarity)
{
    std::string temp = "";

    switch (rarity)
    {
    case RarityCommon:
        temp += "Common ";
        break;
    case RarityUncommon:
        temp += "Uncommon ";
        break;
    case RarityRare:
        temp += "Rare ";
        break;
    case RarityEpic:
        temp += "Epic ";
        break;
    case RarityLegendary:
        temp += "Legendary ";
        break;
    default:
        break;
    }

    switch (itemType)
    {
    case ItemTypeFood:
        temp += "food";
        break;
    case ItemTypeToy:
        temp += "toy";
        break;
    case ItemTypeWater:
        temp += "water";
        break;
    case ItemTypeFertilizer:
        temp += "fertilizer";
        break;
    case ItemTypeTreasure:
        temp += "treasure";
        break;
    default:
        break;
    }

    return temp;
}

void Item::setStats(ItemType itemType, Rarity rarity)
{
    switch (itemType)
    {
    case ItemTypeFood:
        setNutritionChange((int)rarity + 1);
        break;
    case ItemTypeToy:
        setHappinessChange((int)rarity + 1);
        break;
    case ItemTypeWater:
        setHydrationChange((int)rarity + 1);
        break;
    case ItemTypeFertilizer:
        setHealthChange((int)rarity + 1);
        break;
    case ItemTypeTreasure:
        setMoneyChange((int)rarity + 1);
        break;
    default:
        break;
    }
}


void printItemVector(std::vector<Item> vector)
{
    for(Item item : vector)
    {
        std::cout  << item.getItemName() << std::endl;
    }
}