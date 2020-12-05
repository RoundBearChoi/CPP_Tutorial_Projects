#pragma once
#include "PlayerInput.h"
#include "ItemCreator.h"

namespace Roundbeargames
{
	class ItemProcessor
	{
	public:
		void Run()
		{
			ItemCreator itemCreator;
			PlayerInput playerInput;
			char input = '0';

			while (input != 'q')
			{
				WeaponData* weaponData = itemCreator.CreateRandomWeapon();
				weaponData->Render();

				input = playerInput.GetInput();
			}
		}

		ItemProcessor()
		{
			std::cout << "constructing item processor.." << std::endl;
			std::cout << std::endl;
		}

		~ItemProcessor()
		{
			std::cout << std::endl;
			std::cout << "destructing item processor.." << std::endl;
		}
	};
}