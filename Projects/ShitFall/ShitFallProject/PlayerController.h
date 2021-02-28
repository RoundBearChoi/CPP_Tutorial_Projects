#pragma once
#include "StateController.h"
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
	class PlayerController : public StateController
	{
	public:
		PlayerController(ObjData& objData, int _initialStateIndex)
		{
			IF_COUT{ std::cout << "constructing PlayerController" << std::endl; }
			
			MakeTransition(objData, _initialStateIndex);
		}

		~PlayerController() override
		{
			IF_COUT{ std::cout << "destructing PlayerController" << std::endl; }

			delete currentState;
		}

		void MakeTransition(ObjData& objData, int index) override
		{
			delete currentState;
			currentStateIndex = index;

			if (index == (int)PlayerStateType::DUMMY)
			{
				currentState = stateCreator.CreateState<PlayerDummy>(objData);
			}
			else if (index == (int)PlayerStateType::GAME_START)
			{
				currentState = stateCreator.CreateState<PlayerGameStart>(objData);
			}
			else if (index == (int)PlayerStateType::IDLE)
			{
				currentState = stateCreator.CreateState<PlayerIdle>(objData);
			}
			else if (index == (int)PlayerStateType::MOVE_LEFT)
			{
				currentState = stateCreator.CreateState<PlayerMoveLeft>(objData);
			}
			else if (index == (int)PlayerStateType::MOVE_RIGHT)
			{
				currentState = stateCreator.CreateState<PlayerMoveRight>(objData);
			}
			else if (index == (int)PlayerStateType::DEAD)
			{
				currentState = stateCreator.CreateState<PlayerDeath>(objData);
			}
		}
	};
}