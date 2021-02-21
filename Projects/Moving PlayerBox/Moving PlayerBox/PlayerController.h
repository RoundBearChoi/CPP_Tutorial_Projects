#pragma once
#include "ObjController.h"
#include "State.h"
#include "PlayerStateType.h"
#include "PlayerGameStart.h"
#include "PlayerIdle.h"
#include "PlayerMoveLeft.h"
#include "PlayerMoveRight.h"

namespace RB
{
	class PlayerController : public ObjController
	{
	public:
		PlayerController()
		{
			std::cout << "constructing PlayerController" << std::endl;

			MakeTransition((int)PlayerStateType::GAME_START);
		}

		~PlayerController() override
		{
			std::cout << "destructing PlayerController" << std::endl;
			delete currentState;
		}

		void UpdateObj(olc::vf2d& position, const GameData& gameData) override
		{
			currentState->UpdateState(position, gameData);
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

		bool MakeTransition(int index) override
		{
			if (index == (int)PlayerStateType::GAME_START)
			{
				return CreateState<PlayerGameStart>();
			}
			else if (index == (int)PlayerStateType::IDLE)
			{
				return CreateState<PlayerIdle>();
			}
			else if (index == (int)PlayerStateType::MOVE_LEFT)
			{
				return CreateState<PlayerMoveLeft>();
			}
			else if (index == (int)PlayerStateType::MOVE_RIGHT)
			{
				return CreateState<PlayerMoveRight>();
			}
			else if (index == (int)PlayerStateType::DEAD)
			{

			}

			return false;
		}

		bool MakeChildObj() override
		{
			return false;
		}
	};
}