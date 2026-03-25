#include "ExtraItem.h"

Alchemist::ExtraItem::ExtraItem() : ExtraItem("", "")
{
}

Alchemist::ExtraItem::ExtraItem(std::string name, std::string description) : ItemObject(EItemType::Extra, name, description)
{
}

Alchemist::ExtraItem::ExtraItem(const ExtraItem& other) : ItemObject(other)
{
}

Alchemist::ExtraItem Alchemist::ExtraItem::operator=(const ExtraItem& other)
{
    if (this == &other) {
        return *this;
    }
    ItemObject::operator=(other);

    return *this;
}

Alchemist::ExtraItem::~ExtraItem()
{
}
