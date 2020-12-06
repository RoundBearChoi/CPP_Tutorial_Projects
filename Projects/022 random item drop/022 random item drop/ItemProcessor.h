#pragma once
#include "PlayerInput.h"
#include "RandomWeaponGenerator.h"

namespace Roundbeargames
{
	class ItemProcessor
	{
	public:
		void Run()
		{
			RandomWeaponGenerator weaponGenerator;
			PlayerInput playerInput;
			char input = '0';

			while (input != 'q')
			{
				WeaponData* weaponData = weaponGenerator.GetWeaponDrop();
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