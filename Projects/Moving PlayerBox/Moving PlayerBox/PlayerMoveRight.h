#pragma once
#include "State.h"
#include "PlayerStateType.h"

namespace RB
{
	class PlayerMoveRight : public State
	{
	public:
		PlayerMoveRight()
		{
			std::cout << "constructing State: PlayerMoveRight" << std::endl;
		}

		~PlayerMoveRight()
		{
			std::cout << "destructing State: PlayerMoveRight" << std::endl;
		}

		void UpdateState(ObjData& objData, const GameData& gameData) override
		{
			objData.position.x += 5.1f;

			if (gameData.inputXAxis == 0)
			{
				nextStateIndex = (int)PlayerStateType::IDLE;
			}
			else if (gameData.inputXAxis < 0)
			{
				nextStateIndex = (int)PlayerStateType::MOVE_LEFT;
			}

			std::cout << "player pos: " << objData.position.x << ", " << objData.position.y << std::endl;
		}

		void UpdateState2(GameObj* ptrObj, const GameData& gameData) override
		{

		}
	};
}