#pragma once
#include "State.h"
#include "StateType.h"
#include "GameSpriteType.h"

namespace RB
{
	class PlayerMoveLeft;
	class PlayerMoveRight;

	class PlayerIdle : public State
	{
	public:
		PlayerIdle(ObjData& objData)
		{
			IF_COUT{ std::cout << "constructing State: PlayerIdle" << std::endl; }

			stateAnimation.SetParams((int)GameSpriteType::idle_sheet, 300, 80, 6, 1, 6, false);
			stateAnimation.SetDelayTime(500);
		}

		~PlayerIdle()
		{
			IF_COUT{ std::cout << "destructing State: PlayerIdle" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			if (gameData.inputXAxis < 0)
			{
				nextState = State::CreateState<PlayerMoveLeft>(objData);
			}

			if (gameData.inputXAxis > 0)
			{
				nextState = State::CreateState<PlayerMoveRight>(objData);
			}
		}
	};
}