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

			CreateTransition((int)PlayerStateType::GAME_START);
		}

		~PlayerController() override
		{
			std::cout << "destructing PlayerController" << std::endl;
			delete currentState;
		}

		bool CreateTransition(int index) override
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