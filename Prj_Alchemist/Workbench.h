#pragma once
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "PotionItem.h"
#include "ItemRecipe.h"

namespace Alchemist {
	class Workbench
	{
	public:
		std::unordered_map<ItemObject, uint32_t> GetInputIngredients() const {
			// 입력받은 재료를 저장할 목록
			std::unordered_map<ItemObject, uint32_t> ingredients;

			std::cout << "재료 입력을 끝내려면 '끝'을 입력해 주십시오." << std::endl;
			while (true) {
				// 재료 이름, 개수 입력 받기
				std::string ingredientName;
				std::uint32_t ingredientCount;

				std::cout << "제작 재료 이름과 개수를 입력해주십시오.(Ex. 공병 3)" << std::endl;
				std::cin >> ingredientName;

				// "끝" 입력을 감지하여 반복문 탈출
				if (ingredientName == "끝") {
					// 입력 버퍼 초기화
					std::cin.clear();
					std::cin.ignore(LLONG_MAX, '\n');
					break;
				}

				std::cin >> ingredientCount;

				// 입력 중 오류가 발생하지 않으면 재료 목록에 추가
				if (std::cin.fail() == false) {
					ItemObject ingredient = PotionItem(ingredientName, "");

					ingredients.insert({ ingredient, ingredientCount });
					continue;
				}

				// 입력 버퍼 초기화
				std::cin.clear();
				std::cin.ignore(LLONG_MAX, '\n');
				std::cout << "잘못된 값을 입력하였습니다. 다시 입력해주십시오." << std::endl;
			}

			return ingredients;
		}

		// 아이템 이름을 사용하여 레시피를 추가
		void AddRecipe(std::string itemName) {
			PotionItem resultItem = PotionItem(itemName);
			std::unordered_map<ItemObject, uint32_t> ingredients = GetInputIngredients();
			
			// 재료 목록이 비어있는 경우 등록 불가
			if (ingredients.empty() == true) {
				std::cout << "재료를 1개 이상 등록해야 합니다." << std::endl;
				return;
			}

			// 레시피 생성
			ItemRecipe recipe = ItemRecipe(resultItem, ingredients);

			// 중복 레시피 검색
			if (std::find(recipeList.begin(), recipeList.end(), recipe) != recipeList.end()) {
				std::cout << "이미 등록된 레시피입니다." << std::endl;
				return;
			}

			// 레시피 등록
			recipeList.push_back(recipe);
		}
		
		// 인덱스 번호를 사용하여 레시피 삭제
		void RemoveRecipe(size_t index) {
			if (index < 1) {
				std::cout << "index 값은 1보다 크거나 같아야 합니다." << std::endl;
				return;
			}
			--index;
			recipeList.erase(recipeList.begin() + index);
			return;
		}

		// 제작 결과물 이름을 이용하여 레시피 검색
		ItemRecipe FindRecipeByName(const std::string& itemName) const {
			// 레시피 이름에 찾고자 하는 아이템 이름이 포함되어있는지 검색
			auto it = std::find_if(recipeList.begin(), recipeList.end(), [itemName](const ItemRecipe& recipe) {
				std::string recipeName = recipe.GetRecipeName();
				if (recipeName.find(itemName) != -1) {
					return true;
				}
				return false;
				});

			// 레시피가 존재하면 반환
			if (it != recipeList.end()) {
				return *it;
			}
			// 레시피가 존재하지 않으면 EmptyRecipe 반환
			return ItemRecipe::GetEmptyRecipe();
		}

		// 제작 재료 아이템 이름을 이용하여 레시피 검색
		std::vector<ItemRecipe> FindRecipeByIngredient(const std::string& ingredientName) const {
			std::vector<ItemRecipe> buffer;

			// 레시피 리스트 전체 순회
			for (const ItemRecipe& recipe : recipeList) {
				// 레시피의 재료 목록 받아오기
				std::unordered_map<ItemObject, uint32_t> ingredients = recipe.GetIngredients();

				// 재료 목록에서 아이템 이름의 일치 여부 확인
				for (const auto& pair : ingredients) {
					if (pair.first.GetName() == ingredientName) {
						// 버퍼에 레시피 추가
						buffer.push_back(recipe);
						// 다음 레시피 검색
						break;
					}
				}
			}
			return buffer;
		}

		// print names of all recipes
		void DisplayAllRecipes() const {
			std::cout << "========== Load All recipes ==========" << std::endl;
			if (recipeList.empty() == true) {
				std::cout << "등록된 레시피가 존재하지 않습니다." << std::endl;
				return;
			}
			else {
				for (int i = 0; i < recipeList.size(); ++i) {
					std::cout << i + 1 << " ";
					recipeList[i].DisplayRecipe();
				}
			}
			std::cout << "======================================" << std::endl;
			return;
		}

	protected:
		std::vector<ItemRecipe> recipeList;
	};
}
