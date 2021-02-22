#pragma once
#include "State.h"
#include "PlayerStateType.h"

namespace RB
{
	class PlayerMoveLeft : public State
	{
	public:
		PlayerMoveLeft()
		{
			std::cout << "constructing State: PlayerMoveLeft" << std::endl;
		}

		~PlayerMoveLeft()
		{
			std::cout << "destructing State: PlayerMoveLeft" << std::endl;
		}

		void UpdateState(ObjData& objData, const GameData& gameData) override
		{
			objData.position.x -= 5.1f;

			if (gameData.inputXAxis == 0)
			{
				nextStateIndex = (int)PlayerStateType::IDLE;
			}
			else if (gameData.inputXAxis > 0)
			{
				nextStateIndex = (int)PlayerStateType::MOVE_RIGHT;
			}

			std::cout << "player pos: " << objData.position.x << ", " << objData.position.y << std::endl;
		}

		void UpdateState2(GameObj* ptrObj, const GameData& gameData) override
		{

		}
	};
}