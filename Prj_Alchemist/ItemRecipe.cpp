#include "ItemRecipe.h"
#include <iostream>

Alchemist::ItemRecipe::ItemRecipe(const ItemObject resultItem)
{
	this->resultItem = std::make_shared<ItemObject>(resultItem);
}

Alchemist::ItemRecipe::ItemRecipe(const ItemObject resultItem, const std::initializer_list<std::pair<ItemObject, uint8_t>> initializeList)
{
	this->resultItem = std::make_shared<ItemObject>(resultItem);
	this->ingredients.reserve(initializeList.size());
	for (const std::pair<ItemObject, uint8_t>& pair : initializeList) {
		ingredients.insert(pair);
	}
}

Alchemist::ItemRecipe::~ItemRecipe() {
	ingredients.clear();
	resultItem.reset();
}

/// <summary>
/// 레시피에 재료 아이템을 임의 개수만큼 추가
/// </summary>
/// <param name="ingredient">재료 아이템</param>
/// <param name="count">재료 개수</param>
void Alchemist::ItemRecipe::AddIngredient(const ItemObject& ingredient, const uint32_t count) {
	// make shared_ptr with item information of ingredient
	// if ingredient Item was in list
	if (ingredients.find(ingredient) != ingredients.end()) {
		// increase count.
		ingredients[ingredient] += count;
	}
	else {
		ingredients.insert({ ingredient, count });
	}
	return;
}

/// <summary>
/// 레시피에 재료 아이템을 임의 개수만큼 제거
/// </summary>
/// <param name="ingredient">재료 아이템</param>
/// <param name="count">재료 개수</param>
void Alchemist::ItemRecipe::RemoveIngredient(const ItemObject& ingredient, const uint32_t count) {
	// if ingredient Item was in list
	if (ingredients.find(ingredient) != ingredients.end()) {

		// if ingredient count on list was more than count, decrease count
		if (ingredients[ingredient] > count) {
			ingredients[ingredient] -= count;
		}
		else {
			// erase key
			ingredients.erase(ingredient);
		}
	}
	return;
}

void Alchemist::ItemRecipe::ShowRecipe() const
{
	std::cout << " ----- " << resultItem->GetName() << " 제작 재료 목록 ----- " << std::endl;
	for (const auto& pair : ingredients) {
		std::cout << " + " << pair.first.GetName() << " " << pair.second << "개" << std::endl;
	}
	std::cout << " ----- ---------- ---------- ----- " << std::endl;
	return;
}

// 레시피 이름
std::string Alchemist::ItemRecipe::GetRecipeName() const {
	std::string recipeName = resultItem->GetName();
	recipeName.append(" 레시피");
	return recipeName;
}

// 재료 목록
std::unordered_map<Alchemist::ItemObject, uint8_t> Alchemist::ItemRecipe::GetIngredients() const
{
	return ingredients;
}
// 제작 결과물
std::shared_ptr<Alchemist::ItemObject> Alchemist::ItemRecipe::GetResultItem() const
{
	return resultItem;
}

void Alchemist::ItemRecipe::SetResultItem(std::shared_ptr<ItemObject> value) {
	this->resultItem = value;
}
