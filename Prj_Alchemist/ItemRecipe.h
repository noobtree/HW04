#pragma once
#include <memory>
#include <unordered_map>
#include <initializer_list>
#include "ItemObject.h"

namespace std {
	/// <summary>
	/// ItemRecipe에서 std::unordered_map을 사용하기 위한 해시값 생성 정의
	/// </summary>
	template <>
	struct hash<Alchemist::ItemObject> {
		size_t operator()(const Alchemist::ItemObject& resultItem) const {
			// itemName을 기준으로 해시값 생성
			return std::hash<std::string>()(resultItem.GetName());
		}
	};
}

namespace Alchemist {

	class ItemRecipe
	{
	public:
		// Constructor
		ItemRecipe(const ItemObject resultItem);
		ItemRecipe(const ItemObject resultItem, const std::initializer_list<std::pair<ItemObject, uint8_t>> ingredientsList);

		// prevent copy
		ItemRecipe(const ItemRecipe& other) = delete;

		virtual ~ItemRecipe();

		/// <summary>
		/// 레시피에 재료 아이템을 임의 개수만큼 추가
		/// </summary>
		/// <param name="ingredient">재료 아이템</param>
		/// <param name="count">재료 개수</param>
		void AddIngredient(const ItemObject& ingredient, const uint32_t count = 1);

		/// <summary>
		/// 레시피에 재료 아이템을 임의 개수만큼 제거
		/// </summary>
		/// <param name="ingredient">재료 아이템</param>
		/// <param name="count">재료 개수</param>
		void RemoveIngredient(const ItemObject& ingredient, const uint32_t count = 1);

		/// <summary>
		/// 제작법을 출력
		/// </summary>
		void ShowRecipe() const;

		// 레시피 이름
		std::string GetRecipeName() const;

		// 재료 목록
		std::unordered_map<ItemObject, uint8_t> GetIngredients() const;
		// 제작 결과물
		std::shared_ptr<ItemObject> GetResultItem() const;
		
		void SetResultItem(const std::shared_ptr<ItemObject> value);

	protected:
		/// <summary>
		/// 재료 목록 { 재료 아이템, 재료 개수 }
		/// </summary>
		std::unordered_map<ItemObject, uint8_t> ingredients;

		/// <summary>
		/// 제작 결과물
		/// </summary>
		std::shared_ptr<ItemObject> resultItem;
	};

	// PotionRecipe 클래스: 재료 목록을 vector<string>으로 변경
	class PotionRecipe {
	public:
		std::string potionName;
		std::vector<std::string> ingredients; // 단일 재료에서 재료 '목록'으로 변경

		// 생성자: 재료 목록을 받아 초기화하도록 수정
		PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients)
			: potionName(name), ingredients(ingredients) {
		}
	};
}
