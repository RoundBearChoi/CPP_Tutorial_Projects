#pragma once
#include "State.h"

namespace RB
{
	class PlayerDeath : public State
	{
	public:
		PlayerDeath()
		{
			IF_COUT{ std::cout << "constructing State: PlayerDeath" << std::endl; }
			
		}

		~PlayerDeath()
		{
			IF_COUT{ std::cout << "destructing State: PlayerDeath" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{

		}
	};
}