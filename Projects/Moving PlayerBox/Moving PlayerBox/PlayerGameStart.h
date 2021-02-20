#pragma once
#include "PlayerState.h"
#include "UpdateData.h"
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

		void UpdateState(UpdateData &updateData) override
		{
			updateData.pos = { 300.0f, 650.0f };
			*nextStatePtr = (int)PlayerStateType::IDLE;
		}
	};
}