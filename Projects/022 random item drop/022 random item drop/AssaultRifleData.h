#pragma once
#include "WeaponData.h"
#include "AssaultRifleRender.h"

namespace Roundbeargames
{
	class AssaultRifleData : public WeaponData
	{
	public:
		~AssaultRifleData() override
		{
			std::cout << "destructing AssaultRifle data: " << weaponID << std::endl;
			delete itemRender;
		}

		void InitWeaponData(int nIndex) override
		{
			SetWeaponID(nIndex);

			if (IsInitialized() == false)
			{
				std::cout << "constructing AssaultRifleRender: " << weaponID << std::endl;
				itemRender = new AssaultRifleRender();
				itemRender->SetRenderID(weaponID);
			}
		}

		void Render()
		{
			itemRender->ShowImage();
		}
	};
}