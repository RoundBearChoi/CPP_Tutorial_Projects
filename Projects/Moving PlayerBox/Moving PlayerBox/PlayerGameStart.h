#pragma once
#include "State.h"
#include "UpdateData.h"
#include "PlayerStateType.h"

namespace RB
{
	class PlayerGameStart : public State
	{
		void UpdateState(UpdateData &updateData) override
		{
			updateData.pos = { 300.0f, 650.0f };
			*nextStatePtr = (int)PlayerStateType::IDLE;
		}
	};
}