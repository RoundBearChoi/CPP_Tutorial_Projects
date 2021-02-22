#pragma once
#include "State.h"
#include "GameData.h"
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

		void UpdateState(olc::vf2d& pos, const GameData& gameData) override
		{
			pos.x += 5.0f;

			if (gameData.inputXAxis == 0)
			{
				nextStateIndex = (int)PlayerStateType::IDLE;
			}
			else if (gameData.inputXAxis < 0)
			{
				nextStateIndex = (int)PlayerStateType::MOVE_LEFT;
			}
		}
	};
}