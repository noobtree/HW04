#include "ItemRecipe.h"
#include <iostream>
#include <iomanip>

Alchemist::ItemRecipe::ItemRecipe(const ItemObject resultItem)
{
	this->resultItem = std::make_shared<ItemObject>(resultItem);
}

Alchemist::ItemRecipe::ItemRecipe(const ItemObject resultItem, const std::unordered_map<ItemObject, uint32_t> ingredients)
{
	this->resultItem = std::make_shared<ItemObject>(resultItem);
	this->ingredients = ingredients;
}

Alchemist::ItemRecipe::ItemRecipe(const ItemRecipe& other)
{
	this->resultItem = other.resultItem;
	this->ingredients = other.ingredients;
}

Alchemist::ItemRecipe Alchemist::ItemRecipe::operator=(const ItemRecipe& other)
{
	this->resultItem = other.resultItem;
	this->ingredients = other.ingredients;

	return *this;
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

// 레시피를 출력
void Alchemist::ItemRecipe::DisplayRecipe() const
{
	// 제작 결과물 이름 출력
	std::cout << resultItem->GetName() << " = ";

	// 제작 재료 이름, 개수 출력
	for (auto it = ingredients.begin(); it != ingredients.end(); ++it) {
		std::cout << it->first.GetName() << " " << std::setw(2) << it->second << "개";

		// 구획 문자 출력
		if (std::next(it) != ingredients.end()) {
			std::cout << " + ";
		}
	}
	// 줄바꿈 출력
	std::cout << std::endl;
	return;
}

// 레시피 이름
std::string Alchemist::ItemRecipe::GetRecipeName() const {
	if (resultItem != nullptr) {
		std::string recipeName = resultItem->GetName();
		recipeName.append(" Recipe");
		return recipeName;
	}
	return "Empty Recipe";
}

// 재료 목록
std::unordered_map<Alchemist::ItemObject, uint32_t> Alchemist::ItemRecipe::GetIngredients() const
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

bool Alchemist::ItemRecipe::operator==(const ItemRecipe& other)
{
	// 제작 결과물 비교
	if (this->resultItem.get() == this->resultItem.get()) {
		// 제작 재료의 종류 개수 비교
		if (this->ingredients.size() == other.ingredients.size()) {
			// 제작 재료 비교
			if (std::equal(this->ingredients.begin(), this->ingredients.end(), other.ingredients.begin(), other.ingredients.end()) == true) {
				return true;
			}
		}
	}
	return false;
}

bool Alchemist::ItemRecipe::operator!=(const ItemRecipe& other)
{
	return (*this == other) == false;
}

const Alchemist::ItemRecipe Alchemist::ItemRecipe::GetEmptyRecipe() {
	return ItemRecipe();
}
