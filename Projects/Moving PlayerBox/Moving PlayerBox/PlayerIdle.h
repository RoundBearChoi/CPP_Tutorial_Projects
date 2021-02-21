#pragma once
#include "State.h"
#include "GameData.h"
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

		void UpdateState(olc::vf2d& pos, const GameData& gameData) override
		{
			if (gameData.inputXAxis < -0.01f)
			{
				nextStateIndex = (int)PlayerStateType::MOVE_LEFT;
			}

			if (gameData.inputXAxis > 0.01f)
			{
				nextStateIndex = (int)PlayerStateType::MOVE_RIGHT;
			}
		}
	};
}