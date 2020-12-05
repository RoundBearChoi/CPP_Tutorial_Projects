#pragma once
#include "ModsData.h"

namespace Roundbeargames
{
	class Category3_Mod : public ModsData
	{
		void InitModifierData() override
		{
			defaultModifierCount = 3;
			maxBonusMods = 3;
			modClass = "Legendary";
		}
	};
}