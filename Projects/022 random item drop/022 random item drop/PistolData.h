#pragma once
#include "WeaponData.h"
#include "PistolRender.h"

namespace Roundbeargames
{
	class PistolData : public WeaponData
	{
	public:
		~PistolData() override
		{
			std::cout << "destructing Pistol data: " << weaponID << std::endl;
			delete itemRender;
		}

		void InitWeaponData(int nIndex) override
		{
			SetWeaponID(nIndex);

			if (IsInitialized() == false)
			{
				std::cout << "constructing PistolRender: " << weaponID << std::endl;
				itemRender = new PistolRender();
				itemRender->SetRenderID(weaponID);
			}
		}

		void Render()
		{
			itemRender->ShowImage();
		}
	};
}