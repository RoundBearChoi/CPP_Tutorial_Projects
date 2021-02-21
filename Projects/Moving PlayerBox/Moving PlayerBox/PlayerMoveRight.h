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
			pos.x += gameData.deltaTime * 200.0f;

			// close to 0
			if (gameData.inputXAxis > -0.01f && gameData.inputXAxis < 0.01f)
			{
				*nextStatePtr = (int)PlayerStateType::IDLE;
			}
		}
	};
}