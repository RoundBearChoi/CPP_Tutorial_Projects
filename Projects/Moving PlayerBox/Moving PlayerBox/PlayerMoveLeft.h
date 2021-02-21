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
			pos.x -= gameData.deltaTime * 200.0f;

			// close to 0
			if (gameData.inputXAxis > -0.01f && gameData.inputXAxis < 0.01f)
			{
				*nextStatePtr = (int)PlayerStateType::IDLE;
			}
		}
	};
}