#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Workbench.h"

int main() {
    Alchemist::Workbench workbench = Alchemist::Workbench();

    bool bIsLoop = true;
    while (bIsLoop == true) {
        std::cout << "연금술 공방 관리 시스템" << std::endl;
        std::cout << "1. 레시피 추가" << std::endl;
        std::cout << "2. 모든 레시피 출력" << std::endl;
        std::cout << "3. 물약 이름을 사용하여 레시피 검색" << std::endl;
        std::cout << "4. 재료 이름을 사용하여 레시피 검색" << std::endl;
        std::cout << "5. 종료" << std::endl;
        std::cout << "선택: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "잘못된 입력입니다. 숫자를 입력해주세요." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
        case 1:     // 레시피 추가
        {
            std::string name;
            std::cout << "물약 이름: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);

            workbench.AddRecipe(name);
        }
            break;
        case 2:     // 모든 레시피 출력
        {
            workbench.DisplayAllRecipes();
        }
            break;
        case 3:     // 레시피 검색 (By 물약 이름)
        {
            std::string name;
            std::cout << "물약 이름: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);

            Alchemist::ItemRecipe recipe = workbench.FindRecipeByName(name);

            std::cout << "---------- 레시피 이름 검색 결과 ----------" << std::endl;
            if (recipe != Alchemist::ItemRecipe::GetEmptyRecipe()) {
                recipe.DisplayRecipe();
            }
            else {
                std::cout << "검색 결과가 존재하지 않습니다." << std::endl;
            }
            std::cout << "---------- ---------- ---------- ----------" << std::endl;
        }
            break;
        case 4:     // 레시피 검색 (By 재료 이름)
        {
            std::string name;
            std::cout << "재료 이름: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);

            std::vector<Alchemist::ItemRecipe> recipeList = workbench.FindRecipeByIngredient(name);

            std::cout << "---------- 재료를 사용한 레시피 검색 결과 ----------" << std::endl;
            if (recipeList.empty() == false) {
                for (int i = 0; i < recipeList.size(); ++i) {
                    std::cout << i + 1;
                    recipeList[i].DisplayRecipe();
                }
            }
            else {
                std::cout << "검색 결과가 존재하지 않습니다." << std::endl;
            }
            std::cout << "---------- ---------- ---------- ----------" << std::endl;
        }
            break;
        case 5:     // 종료
        {
            std::cout << "공방 문을 닫습니다..." << std::endl;
            bIsLoop = false;
        }
            break;
        default:
            std::cout << "잘못된 선택입니다. 다시 시도하세요." << std::endl;
            break;
        }
    }

    return 0;
}