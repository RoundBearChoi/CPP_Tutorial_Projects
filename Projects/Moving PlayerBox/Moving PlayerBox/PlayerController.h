#pragma once
#include "StateController.h"
#include "PlayerStateType.h"
#include "PlayerGameStart.h"
#include "PlayerIdle.h"
#include "PlayerMoveLeft.h"
#include "PlayerMoveRight.h"

namespace RB
{
	class PlayerController : public StateController
	{
	public:
		bool MakeTransition(int index) override
		{
			if (index == (int)PlayerStateType::GAME_START)
			{
				stateData.CreateState<PlayerGameStart>();
				return true;
			}
			else if (index == (int)PlayerStateType::IDLE)
			{
				stateData.CreateState<PlayerIdle>();
				return true;
			}
			else if (index == (int)PlayerStateType::MOVE_LEFT)
			{
				stateData.CreateState<PlayerMoveLeft>();
				return true;
			}
			else if (index == (int)PlayerStateType::MOVE_RIGHT)
			{
				stateData.CreateState<PlayerMoveRight>();
				return true;
			}
			else if (index == (int)PlayerStateType::DEAD)
			{

			}

			return false;
		}

		void CheckNextTransition() override
		{
			if (stateData.nextState != 0)
			{
				if (MakeTransition(stateData.nextState))
				{
					stateData.nextState = 0;
				}
			}
		}
	};
}