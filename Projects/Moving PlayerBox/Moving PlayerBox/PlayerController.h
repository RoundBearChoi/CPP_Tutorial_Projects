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
		~PlayerController() override
		{
			std::cout << "destructing PlayerController" << std::endl;
		}

		bool MakeTransition(int index) override
		{
			if (index == (int)PlayerStateType::GAME_START)
			{
				CreateState<PlayerGameStart>();
				return true;
			}
			else if (index == (int)PlayerStateType::IDLE)
			{
				CreateState<PlayerIdle>();
				return true;
			}
			else if (index == (int)PlayerStateType::MOVE_LEFT)
			{
				CreateState<PlayerMoveLeft>();
				return true;
			}
			else if (index == (int)PlayerStateType::MOVE_RIGHT)
			{
				CreateState<PlayerMoveRight>();
				return true;
			}
			else if (index == (int)PlayerStateType::DEAD)
			{

			}

			return false;
		}

		void CheckNextTransition() override
		{
			if (nextState != 0)
			{
				if (MakeTransition(nextState))
				{
					nextState = 0;
				}
			}
		}
	};
}