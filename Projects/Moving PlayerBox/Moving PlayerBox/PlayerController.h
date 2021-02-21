#pragma once
#include "ObjController.h"
#include "PlayerState.h"
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
		PlayerState* currentState = nullptr;
		int nextState = 0;

		PlayerController()
		{
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

		template<class T>
		bool CreateState()
		{
			delete currentState;

			if (std::is_base_of<PlayerState, T>::value)
			{
				currentState = new T();
				currentState->nextStatePtr = &nextState;
				return true;
			}

			return false;
		}

		bool MakeChildObj() override
		{
			if (currentState->testing == 1)
			{
				currentState->testing = 0;
				return true;
			}
			else
			{
				return false;
			}
		}
	};
}