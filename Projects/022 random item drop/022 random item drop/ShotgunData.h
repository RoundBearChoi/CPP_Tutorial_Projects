#pragma once
#include "WeaponData.h"
#include "ShotgunRender.h"

namespace Roundbeargames
{
	class ShotgunData : public WeaponData
	{
	public:
		~ShotgunData() override
		{
			std::cout << "destructing Shotgun data: " << weaponID << std::endl;
			delete itemRender;
		}

		void InitWeaponData(int nIndex) override
		{
			SetWeaponID(nIndex);

			if (IsInitialized() == false)
			{
				std::cout << "constructing ShotgunRender: " << weaponID << std::endl;
				itemRender = new ShotgunRender();
				itemRender->SetRenderID(weaponID);
			}
		}

		void Render()
		{
			itemRender->ShowImage();
		}
	};
}