#pragma once
#include "State.h"
#include "UpdateData.h"
#include "PlayerStateType.h"

namespace RB
{
	class PlayerIdle : public State
	{
	public:
		PlayerIdle()
		{
			std::cout << "player state: PlayerIdle" << std::endl;
		}

		void UpdateState(UpdateData &updateData) override
		{
			if (updateData.inputXAxis < -0.01f)
			{
				*nextStatePtr = (int)PlayerStateType::MOVE_LEFT;
			}

			if (updateData.inputXAxis > 0.01f)
			{
				*nextStatePtr = (int)PlayerStateType::MOVE_RIGHT;
			}
		}
	};
}