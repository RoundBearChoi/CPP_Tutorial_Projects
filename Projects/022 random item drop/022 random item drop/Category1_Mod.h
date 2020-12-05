#pragma once
#include "ModsData.h"

namespace Roundbeargames
{
	class Category1_Mod : public ModsData
	{
		void InitModifierData() override
		{
			defaultModifierCount = 1;
			maxBonusMods = 0;
			modClass = "Common";
		}
	};
}