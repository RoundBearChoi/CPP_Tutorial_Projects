#pragma once
#include "State.h"
#include "GameSpriteType.h"

namespace RB
{
	class PlayerIdle;
	class PlayerMoveRight;

	class PlayerMoveLeft : public State
	{
	public:
		PlayerMoveLeft()
		{
			IF_COUT{ std::cout << "constructing State: PlayerMoveLeft" << std::endl; }
			
			animationController.SetParams((int)GameSpriteType::pixel_run_sheet, 300, 80, 6, 1, 6, true);
			animationController.SetDelayTime(TransitionDelayTable::PLAYER_RUN);
		}

		~PlayerMoveLeft()
		{
			IF_COUT{ std::cout << "destructing State: PlayerMoveLeft" << std::endl; }
		}

		void OnEnter(ObjData& objData, GameData& gameData) override
		{

		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			objData.position.x -= 5.1f;

			if (gameData.inputXAxis == 0)
			{
				nextState = State::CreateState<PlayerIdle>();
			}
			else if (gameData.inputXAxis > 0)
			{
				nextState = State::CreateState<PlayerMoveRight>();
			}

			if (objData.position.x < 0.0f + 25.0f)
			{
				objData.position.x = 0.0f + 25.0f;
			}

			IF_COUT{ std::cout << "player pos: " << objData.position.x << ", " << objData.position.y << std::endl; }
		}
	};
}