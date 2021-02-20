#pragma once
#include "PlayerState.h"
#include "UpdateData.h"
#include "PlayerStateType.h"

namespace RB
{
	class PlayerMoveRight : public PlayerState
	{
	public:
		PlayerMoveRight()
		{
			std::cout << "player state: PlayerMoveRight" << std::endl;
		}

		void UpdateState(UpdateData& updateData) override
		{
			updateData.pos.x += updateData.elapsedTime * 200.0f;

			// close to 0
			if (updateData.inputXAxis > -0.01f && updateData.inputXAxis < 0.01f)
			{
				*nextStatePtr = (int)PlayerStateType::IDLE;
			}
		}
	};
}