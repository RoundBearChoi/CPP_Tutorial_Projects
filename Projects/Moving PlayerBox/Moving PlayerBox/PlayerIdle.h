#pragma once
#include "PlayerState.h"
#include "GameData.h"
#include "PlayerStateType.h"

namespace RB
{
	class PlayerIdle : public PlayerState
	{
	public:
		PlayerIdle()
		{
			std::cout << "player state: PlayerIdle" << std::endl;
		}

		void UpdateState(olc::vf2d& pos, const GameData& gameData) override
		{
			if (gameData.inputXAxis < -0.01f)
			{
				*nextStatePtr = (int)PlayerStateType::MOVE_LEFT;
			}

			if (gameData.inputXAxis > 0.01f)
			{
				*nextStatePtr = (int)PlayerStateType::MOVE_RIGHT;
			}
		}
	};
}