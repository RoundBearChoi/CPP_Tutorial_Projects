#pragma once
#include <vector>
#include "RandomInteger.h"
#include "PistolData.h"
#include "AssaultRifleData.h"
#include "ShotgunData.h"

namespace Roundbeargames
{
	class ItemCreator
	{
	private:
		std::vector<WeaponData*> vecWeaponData;
		RandomInteger randomInteger;

	public:
		WeaponData* CreateRandomWeapon()
		{
			int n = randomInteger.GetInteger(0, 2);
			int weaponIndex = vecWeaponData.size();

			std::cout << std::endl;
			std::cout << "constructing weapon data: " << weaponIndex << std::endl;

			if (n == 0)
			{
				PistolData* pistolData = new PistolData();
				pistolData->InitWeaponData(weaponIndex);
				pistolData->ToggleInitialized();
				vecWeaponData.push_back(pistolData);

				std::cout << "PistolData address: " << pistolData << std::endl;

				return pistolData;
			}
			else if (n == 1)
			{
				AssaultRifleData* assaultRifleData = new AssaultRifleData();
				assaultRifleData->InitWeaponData(weaponIndex);
				assaultRifleData->ToggleInitialized();
				vecWeaponData.push_back(assaultRifleData);

				std::cout << "AssaultRifleData address: " << assaultRifleData << std::endl;

				return assaultRifleData;
			}
			else
			{
				ShotgunData* shotgunData = new ShotgunData();
				shotgunData->InitWeaponData(weaponIndex);
				shotgunData->ToggleInitialized();
				vecWeaponData.push_back(shotgunData);

				std::cout << "ShotgunData address: " << shotgunData << std::endl;

				return shotgunData;
			}
		}

		ItemCreator()
		{
			std::cout << "constructing item creator.." << std::endl;
		}

		~ItemCreator()
		{
			std::cout << std::endl;
			std::cout << "destructing item creator.." << std::endl;

			for (int i = 0; i < vecWeaponData.size(); i++)
			{
				int n = vecWeaponData[i]->GetWeaponID();

				std::cout << std::endl;
				std::cout << "weapon data address: " << vecWeaponData[i] << std::endl;

				delete vecWeaponData[i];
			}
		}
	};
}