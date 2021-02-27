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
		PlayerController(int _initialStateIndex, ObjData& objData)
		{
			IF_COUT{ std::cout << "constructing PlayerController" << std::endl; }
			
			MakeTransition(_initialStateIndex, objData);
		}

		~PlayerController() override
		{
			IF_COUT{ std::cout << "destructing PlayerController" << std::endl; }

			delete currentState;
		}

		void MakeTransition(int index, ObjData& objData) override
		{
			if (index == (int)PlayerStateType::DUMMY)
			{
				CreateState<PlayerDummy>(index, objData);
			}
			else if (index == (int)PlayerStateType::GAME_START)
			{
				CreateState<PlayerGameStart>(index, objData);
			}
			else if (index == (int)PlayerStateType::IDLE)
			{
				CreateState<PlayerIdle>(index, objData);
			}
			else if (index == (int)PlayerStateType::MOVE_LEFT)
			{
				CreateState<PlayerMoveLeft>(index, objData);
			}
			else if (index == (int)PlayerStateType::MOVE_RIGHT)
			{
				CreateState<PlayerMoveRight>(index, objData);
			}
			else if (index == (int)PlayerStateType::DEAD)
			{
				CreateState<PlayerDeath>(index, objData);
			}
		}
	};
}