#pragma once
#include "State.h"
#include "GameSpriteType.h"

namespace RB
{
	class PlayerMoveLeft;
	class PlayerMoveRight;

	class PlayerIdle : public State
	{
	public:
		PlayerIdle()
		{
			IF_COUT{ std::cout << "constructing State: PlayerIdle" << std::endl; }

			animationController.SetParams((int)GameSpriteType::idle_sheet, 300, 80, 6, 1, 6, false);
			animationController.SetDelayTime(TransitionDelayTable::PLAYER_IDLE);
		}

		~PlayerIdle()
		{
			IF_COUT{ std::cout << "destructing State: PlayerIdle" << std::endl; }
		}

		void OnEnter(ObjData& objData, GameData& gameData) override
		{

		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			if (gameData.inputXAxis < 0)
			{
				nextState = State::CreateState<PlayerMoveLeft>();
			}

			if (gameData.inputXAxis > 0)
			{
				nextState = State::CreateState<PlayerMoveRight>();
			}
		}
	};
}