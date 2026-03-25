#pragma once
#include <string>
#include <memory>

namespace Alchemist {
	enum class EItemType {
		Potion	// 포션 아이템
	};

	// abstract class for all Items
	// [protected] itemName : 아이템 이름
	// [protected] itemDescription : 아이템 설명
	// [private] itemType : 아이템 종류
	class ItemObject
	{
	public:
		// Copy Constructor
		ItemObject(const ItemObject& other);
		ItemObject& operator=(const ItemObject& other);

		virtual ~ItemObject();

		bool operator==(const ItemObject& other) const;

		/// <summary>
		/// Get name of Item
		/// </summary>
		std::string GetName() const;
		/// <summary>
		/// Get description of Item
		/// </summary>
		std::string GetDescription() const;
		/// <summary>
		/// Get type of Item
		/// </summary>
		EItemType GetItemType() const;

	protected:
		ItemObject(EItemType type);
		ItemObject(EItemType type, std::string name, std::string description = "");

		/// <summary>
		/// 아이템 이름
		/// </summary>
		std::string itemName;

		/// <summary>
		/// 아이템 설명
		/// </summary>
		std::string itemDescription;

	private:
		/// <summary>
		/// 아이템 타입
		/// </summary>
		EItemType _itemType;
	};
}

