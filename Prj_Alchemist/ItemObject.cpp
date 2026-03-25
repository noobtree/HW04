#include "ItemObject.h"

// Constructor
Alchemist::ItemObject::ItemObject(EItemType type) : ItemObject(type, "", "") {}

Alchemist::ItemObject::ItemObject(EItemType type, std::string name, std::string description) : _itemType(type), itemName(name), itemDescription(description) {
}

// Copy Constructor
Alchemist::ItemObject::ItemObject(const ItemObject& other) {
	this->itemName = other.itemName;
	this->itemDescription = other.itemDescription;
	this->_itemType = other._itemType;
	return;
}

Alchemist::ItemObject& Alchemist::ItemObject::operator=(const ItemObject& other) {
	if (this == &other) {
		return *this;
	}
	this->itemName = other.itemName;
	this->itemDescription = other.itemDescription;
	this->_itemType = other._itemType;
	return *this;
}

Alchemist::ItemObject::~ItemObject() {}

bool Alchemist::ItemObject::operator==(const ItemObject& other) const
{
	return this->itemName == other.itemName;
}

/// <summary>
/// Get name of Item
/// </summary>
std::string Alchemist::ItemObject::GetName() const {
	return itemName;
}

/// <summary>
/// Get description of Item
/// </summary>
std::string Alchemist::ItemObject::GetDescription() const {
	return itemDescription;
}


/// <summary>
/// Get type of Item
/// </summary>
Alchemist::EItemType Alchemist::ItemObject::GetItemType() const {
	return _itemType;
}
