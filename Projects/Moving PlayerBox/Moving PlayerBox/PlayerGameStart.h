#pragma once
#include "State.h"
#include "PlayerStateType.h"
#include "UpdateData.h"

namespace RB
{
	class PlayerGameStart : public State
	{
		void UpdateState(UpdateData &updateData) override
		{
			*nextStatePtr = (int)PlayerStateType::IDLE;
		}
	};
}