#pragma once
#include "State.h"
#include "StateType.h"
#include "GameSpriteType.h"

namespace RB
{
	class PlayerMoveLeft : public State
	{
	public:
		PlayerMoveLeft()
		{
			std::cout << "constructing State: PlayerMoveLeft" << std::endl;
			stateAnimation.SetParams((int)GameSpriteType::playerwalk_dummysheet, 350, 80, 7, 1, 7, true);
		}

		~PlayerMoveLeft()
		{
			std::cout << "destructing State: PlayerMoveLeft" << std::endl;
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			objData.position.x -= 5.1f;

			if (gameData.inputXAxis == 0)
			{
				objData.nextStateIndex = (int)PlayerStateType::IDLE;
			}
			else if (gameData.inputXAxis > 0)
			{
				objData.nextStateIndex = (int)PlayerStateType::MOVE_RIGHT;
			}

			if (objData.position.x < 0.0f + 25.0f)
			{
				objData.position.x = 0.0f + 25.0f;
			}

			std::cout << "player pos: " << objData.position.x << ", " << objData.position.y << std::endl;
		}
	};
}