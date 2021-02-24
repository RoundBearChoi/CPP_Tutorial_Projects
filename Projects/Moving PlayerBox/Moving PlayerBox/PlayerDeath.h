#pragma once
#include "State.h"
namespace RB
{
	class PlayerDeath : public State
	{
	public:
		PlayerDeath()
		{
			std::cout << "constructing State: PlayerDeath" << std::endl;
		}

		~PlayerDeath()
		{
			std::cout << "destructing State: PlayerDeath" << std::endl;
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{

		}
	};
}