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

			//temp
			testing = 1;
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