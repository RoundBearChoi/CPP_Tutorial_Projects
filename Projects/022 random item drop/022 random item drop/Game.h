#pragma once
#include "PlayerInput.h"
#include "RandomWeaponGenerator.h"

namespace Roundbeargames
{
	class Game
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

		Game()
		{
			std::cout << "constructing game.." << std::endl;
			std::cout << std::endl;
		}

		~Game()
		{
			std::cout << std::endl;
			std::cout << "destructing game.." << std::endl;
		}
	};
}