#pragma once
#include "ItemObject.h"

namespace Alchemist {
	class PotionItem : public ItemObject
	{
	public:
		PotionItem();
		PotionItem(std::string name, std::string description);

		PotionItem(const PotionItem& other);
		PotionItem operator=(const PotionItem& other);

		virtual ~PotionItem();
	};
}
