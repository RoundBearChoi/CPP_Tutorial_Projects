#pragma once
#include <vector>
#include <string>
#include "ModifierType.h"

namespace Roundbeargames
{
	class ModsData
	{
	protected:
		int defaultModifierCount = 0;
		int maxBonusMods = 0;
		std::vector<ModifierType> vecModifiers;
		std::string modClass = "none";

	public:
		virtual void InitModifierData() = 0;
	};
}