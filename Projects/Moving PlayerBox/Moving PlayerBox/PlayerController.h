#pragma once
#include "StateController.h"
#include "PlayerGameStart.h"
#include "PlayerIdle.h"

namespace RB
{
	enum class PlayerStateType
	{
		GAME_START,
		IDLE,
		MOVE_LEFT,
		MOVE_RIGHT,
		DEAD,
	};

	class PlayerController : public StateController
	{
	public:
		PlayerController()
		{
			id = 1;
		}

		void MakeTransition(int index) override
		{
			State* newState = nullptr;

			if (index == (int)PlayerStateType::GAME_START)
			{
				newState = CreateState<PlayerGameStart>();
			}
			else if (index == (int)PlayerStateType::IDLE)
			{
				newState = CreateState<PlayerIdle>();
			}
			else if (index == (int)PlayerStateType::MOVE_LEFT)
			{

			}
			else if (index == (int)PlayerStateType::MOVE_RIGHT)
			{

			}
			else if (index == (int)PlayerStateType::DEAD)
			{

			}
		}
	};
}