#pragma once
#include "ObjController.h"
#include "State.h"
#include "StateType.h"
#include "DevSettings.h"

#include "PlayerDummy.h"
#include "PlayerGameStart.h"
#include "PlayerIdle.h"
#include "PlayerMoveLeft.h"
#include "PlayerMoveRight.h"
#include "PlayerDeath.h"

namespace RB
{
	class PlayerController : public ObjController
	{
	public:
		PlayerController(int _initialStateIndex)
		{
			IF_COUT{ std::cout << "constructing PlayerController" << std::endl; }
			
			MakeTransition(_initialStateIndex);
		}

		~PlayerController() override
		{
			IF_COUT{ std::cout << "destructing PlayerController" << std::endl; }

			delete currentState;
		}

		void MakeTransition(int index) override
		{
			if (index == (int)PlayerStateType::DUMMY)
			{
				CreateState<PlayerDummy>(index);
			}
			else if (index == (int)PlayerStateType::GAME_START)
			{
				CreateState<PlayerGameStart>(index);
			}
			else if (index == (int)PlayerStateType::IDLE)
			{
				CreateState<PlayerIdle>(index);
			}
			else if (index == (int)PlayerStateType::MOVE_LEFT)
			{
				CreateState<PlayerMoveLeft>(index);
			}
			else if (index == (int)PlayerStateType::MOVE_RIGHT)
			{
				CreateState<PlayerMoveRight>(index);
			}
			else if (index == (int)PlayerStateType::DEAD)
			{
				CreateState<PlayerDeath>(index);
			}
		}
	};
}