#include <random>

#include "Item.hpp"

Item::Item()
{
    m_itemType = static_cast<ItemType>(rand() % 5);
    m_rarity = static_cast<Rarity>(rand() % 5);
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
