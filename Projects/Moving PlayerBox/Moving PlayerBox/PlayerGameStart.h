#pragma once
#include "PlayerState.h"
#include "GameData.h"
#include "PlayerStateType.h"

namespace RB
{
	class PlayerGameStart : public PlayerState
	{
	public:
		PlayerGameStart()
		{
			std::cout << "player state: GameStart" << std::endl;
		}

		void UpdateState(olc::vf2d& pos, const GameData& gameData) override
		{
			pos = { 300.0f, 650.0f };
			*nextStatePtr = (int)PlayerStateType::IDLE;
		}
	};
}