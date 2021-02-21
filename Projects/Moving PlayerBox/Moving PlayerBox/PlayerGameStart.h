#pragma once
#include "State.h"
#include "GameData.h"
#include "PlayerStateType.h"

namespace RB
{
	class PlayerGameStart : public State
	{
	public:
		PlayerGameStart()
		{
			std::cout << std::endl;
			std::cout << "constructing State: GameStart" << std::endl;
		}

		~PlayerGameStart()
		{
			std::cout << "destructing State: GameStart" << std::endl;
		}

		void UpdateState(olc::vf2d& pos, const GameData& gameData) override
		{
			pos = { 300.0f, 650.0f };
			nextStateIndex = (int)PlayerStateType::IDLE;
		}
	};
}