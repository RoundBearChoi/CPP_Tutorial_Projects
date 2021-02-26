#pragma once
#include "State.h"
#include "DevSettings.h"

namespace RB
{
	class PlayerDummy : public State
	{
	public:
		PlayerDummy()
		{
			IF_COUT{ std::cout << "constructing State: PlayerDummy" << std::endl; }
		}

		~PlayerDummy()
		{
			IF_COUT{ std::cout << "destructing State: PlayerDummy" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			objData.position = { 300.0f, 650.0f };
		}
	};
}