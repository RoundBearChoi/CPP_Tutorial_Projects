#pragma once
#include "State.h"
#include "InputData.h"
#include "PlayerStateType.h"

namespace RB
{
	class PlayerGameStart : public State
	{
		void UpdateState(InputData &_inputData, VecData &vecData) override
		{
			*nextStatePtr = (int)PlayerStateType::IDLE;
		}

		void UUState() override
		{

		}
	};
}