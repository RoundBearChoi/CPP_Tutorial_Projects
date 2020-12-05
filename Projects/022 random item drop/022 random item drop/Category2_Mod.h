#pragma once
#include "ModsData.h"

namespace Roundbeargames
{
	class Category2_Mod : public ModsData
	{
		void InitModifierData() override
		{
			defaultModifierCount = 2;
			maxBonusMods = 1;
			modClass = "Rare";
		}
	};
}