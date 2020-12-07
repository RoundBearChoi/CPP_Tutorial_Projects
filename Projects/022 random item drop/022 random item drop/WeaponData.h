#pragma once
#include "ItemRender.h"
#include "ModsData.h"

namespace Roundbeargames
{
	class WeaponData
	{
	protected:
		int weaponID = 0;
		bool isInitialized = false;
		int Damage = 0;
		int RateOfFire = 0;
		int MagSize = 0;
		int Accuracy = 0;
		int Recoil = 0;
		int ReloadTime = 0;

		ItemRender* itemRender = nullptr;
		ModsData* modData = nullptr;
		
	public:
		virtual void InitWeaponData(int nIndex) = 0;

		virtual ~WeaponData()
		{

		}

		void Render()
		{
			itemRender->ShowImage();
		}

		void SetWeaponID(int nIndex)
		{
			weaponID = nIndex;
		}

		int GetWeaponID()
		{
			return weaponID;
		}

		bool IsInitialized()
		{
			return isInitialized;
		}

		void ToggleInitialized()
		{
			isInitialized = true;
		}
	};
}