#pragma once
#include "State.h"
#include "StateType.h"

namespace RB
{
	class PlayerIdle : public State
	{
	public:
		PlayerIdle()
		{
			IF_COUT{ std::cout << "constructing State: PlayerIdle" << std::endl; }
			
		}

		~PlayerIdle()
		{
			IF_COUT{ std::cout << "destructing State: PlayerIdle" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			if (gameData.inputXAxis < 0)
			{
				objData.nextStateIndex = (int)PlayerStateType::MOVE_LEFT;
			}

			if (gameData.inputXAxis > 0)
			{
				objData.nextStateIndex = (int)PlayerStateType::MOVE_RIGHT;
			}
		}
	};
}