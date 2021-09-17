class Item
{
    Item(int happinessChange, int hydrationChange, int nutritionChange, int healthChange);
    ~Item() = default;
public:
    ItemType getItemType();
    Rarity getRarity();
    int getHappinessChange();
    int getHydrationChange();
    int getNutritionChange();
    int getHealthChange();

private:
    ItemType m_itemType;
    Rarity m_rarity;
    int m_happinessChange;
    int m_hydrationChange;
    int m_nutritionChange;
    int m_healthChange;
};

enum ItemType
{
    ItemTypeFood,
    ItemTypeToy,
    ItemTypeWater,
    ItemTypeFertilizer,
    ItemTypeTreasure

};

enum Rarity
{
    RarityRare,
    RarityEpic,
    RarityLegendary

};

