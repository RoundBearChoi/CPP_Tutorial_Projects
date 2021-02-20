#pragma once
#include "PlayerState.h"
#include "PlayerStateType.h"
#include "PlayerGameStart.h"
#include "PlayerIdle.h"
#include "PlayerMoveLeft.h"
#include "PlayerMoveRight.h"

namespace RB
{
	class PlayerController
	{
	public:
		PlayerState* currentState = nullptr;
		int nextState = 0;

		~PlayerController()
		{
			std::cout << "destructing PlayerController" << std::endl;
			delete currentState;
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

		bool MakeTransition(int index)
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

		void Update(UpdateData& updateData)
		{
			currentState->UpdateState(updateData);
		}

		void CheckNextTransition()
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