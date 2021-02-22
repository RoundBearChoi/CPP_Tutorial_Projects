#pragma once
#include "State.h"
#include "GameData.h"
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

		void UpdateState(olc::vf2d& pos, const GameData& gameData) override
		{
			pos.x -= 5.0f;

			if (gameData.inputXAxis == 0)
			{
				nextStateIndex = (int)PlayerStateType::IDLE;
			}
		}
	};
}