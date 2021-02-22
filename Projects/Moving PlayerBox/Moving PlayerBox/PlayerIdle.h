#pragma once
#include "State.h"
#include "PlayerStateType.h"

namespace RB
{
	class PlayerIdle : public State
	{
	public:
		PlayerIdle()
		{
			std::cout << "constructing State: PlayerIdle" << std::endl;
		}

		~PlayerIdle()
		{
			std::cout << "destructing State: PlayerIdle" << std::endl;
		}

		void UpdateState(ObjData& objData, const GameData& gameData) override
		{
			if (gameData.inputXAxis < 0)
			{
				nextStateIndex = (int)PlayerStateType::MOVE_LEFT;
			}

			if (gameData.inputXAxis > 0)
			{
				nextStateIndex = (int)PlayerStateType::MOVE_RIGHT;
			}
		}

		void UpdateState2(GameObj* ptrObj, const GameData& gameData) override
		{

		}
	};
}