#pragma once
#include "ItemObject.h"

namespace Alchemist {
	class ExtraItem : public ItemObject
	{
	public:
		ExtraItem();
		ExtraItem(std::string name, std::string description);

		ExtraItem(const ExtraItem& other);
		ExtraItem operator=(const ExtraItem& other);

		virtual ~ExtraItem();
	};
}
