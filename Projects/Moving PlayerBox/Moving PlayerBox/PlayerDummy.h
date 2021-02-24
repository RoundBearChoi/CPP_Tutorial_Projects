#pragma once
#include "State.h"

namespace RB
{
	class PlayerDummy : public State
	{
	public:
		PlayerDummy()
		{
			std::cout << "constructing State: PlayerDummy" << std::endl;
		}

		~PlayerDummy()
		{
			std::cout << "destructing State: PlayerDummy" << std::endl;
		}

		void UpdateState(ObjData& objData, const GameData& gameData) override
		{
			objData.position = { 300.0f, 650.0f };
		}
	};
}