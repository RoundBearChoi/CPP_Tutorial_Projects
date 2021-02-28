#pragma once
#include "State.h"
#include "StateType.h"
#include "GameSpriteType.h"

namespace RB
{
	class PlayerIdle;
	class PlayerMoveLeft;

	class PlayerMoveRight : public State
	{
	public:
		PlayerMoveRight()
		{
			IF_COUT{ std::cout << "constructing State: PlayerMoveRight" << std::endl; }
			
			stateAnimation.SetParams((int)GameSpriteType::pixel_run_sheet, 300, 80, 6, 1, 6, false);
			stateAnimation.SetDelayTime(50);
		}

		~PlayerMoveRight()
		{
			IF_COUT{ std::cout << "destructing State: PlayerMoveRight" << std::endl; }
		}

		void OnEnter(ObjData& objData, GameData& gameData) override
		{

		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			objData.position.x += 5.1f;

			if (gameData.inputXAxis == 0)
			{
				nextState = State::CreateState<PlayerIdle>();
			}
			else if (gameData.inputXAxis < 0)
			{
				nextState = State::CreateState<PlayerMoveLeft>();
			}

			if (objData.position.x > 600.0f - 25.0f)
			{
				objData.position.x = 600.0f - 25.0f;
			}

			IF_COUT{ std::cout << "player pos: " << objData.position.x << ", " << objData.position.y << std::endl; }
		}
	};
}