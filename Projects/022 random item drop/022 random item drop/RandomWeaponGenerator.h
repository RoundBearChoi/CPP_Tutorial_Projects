#pragma once
#include <vector>
#include "RandomInteger.h"
#include "PistolData.h"
#include "AssaultRifleData.h"
#include "ShotgunData.h"

namespace Roundbeargames
{
	class RandomWeaponGenerator
	{
	private:
		std::vector<WeaponData*> vecWeaponData;
		RandomInteger randomInteger;

		WeaponData* Generate()
		{
			int n = randomInteger.GetInteger(0, 2);
			int weaponIndex = vecWeaponData.size();

			std::cout << std::endl;
			std::cout << "constructing weapon data: " << weaponIndex << std::endl;

			if (n == 0)
			{
				PistolData* pistolData = new PistolData();
				return pistolData;
			}
			else if (n == 1)
			{
				AssaultRifleData* assaultRifleData = new AssaultRifleData();
				return assaultRifleData;
			}
			else
			{
				ShotgunData* shotgunData = new ShotgunData();
				return shotgunData;
			}
		}

	public:
		WeaponData* GetWeaponDrop()
		{
			WeaponData* data = Generate();

			int weaponIndex = vecWeaponData.size();
			data->InitWeaponData(weaponIndex);
			data->ToggleInitialized();
			vecWeaponData.push_back(data);

			std::cout << "weapon address: " << data << std::endl;

			return data;
		}

		RandomWeaponGenerator()
		{
			std::cout << "constructing weapon generator.." << std::endl;
		}

		~RandomWeaponGenerator()
		{
			std::cout << std::endl;
			std::cout << "destructing weapon generator.." << std::endl;

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