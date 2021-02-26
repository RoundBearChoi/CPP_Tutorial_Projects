#pragma once
#include "State.h"

namespace RB
{
	class PlayerWhiteScreen : State
	{
	public:
		PlayerWhiteScreen()
		{
			IF_COUT{ std::cout << "constructing State: PlayerWhiteScreen" << std::endl; }

		}

		~PlayerWhiteScreen()
		{
			IF_COUT{ std::cout << "destructing State: PlayerWhiteScreen" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{

		}
	};
}