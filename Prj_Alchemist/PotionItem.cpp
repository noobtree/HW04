#include "PotionItem.h"

Alchemist::PotionItem::PotionItem() : PotionItem("", "")
{
}

Alchemist::PotionItem::PotionItem(std::string name, std::string description) : ItemObject(EItemType::Potion, name, description)
{
}

Alchemist::PotionItem::PotionItem(const PotionItem& other) : ItemObject(other)
{
}

Alchemist::PotionItem Alchemist::PotionItem::operator=(const PotionItem& other)
{
    if (this == &other) {
        return *this;
    }
    
    ItemObject::operator=(other);

    return *this;
}

Alchemist::PotionItem::~PotionItem()
{
}
