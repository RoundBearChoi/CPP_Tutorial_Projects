#pragma once
#include "State.h"

namespace RB
{
	class PlayerIdle;

	class PlayerGameStart : public State
	{
	public:
		PlayerGameStart()
		{
			IF_COUT
			{
				std::cout << std::endl;
				std::cout << "constructing State: GameStart" << std::endl;
			}

			animationController.SetParams((int)GameSpriteType::idle_sheet, 300, 80, 6, 1, 6, false);
			animationController.data.transitionDelay = (int)TransitionDelayTable::PLAYER_IDLE;
		}

		~PlayerGameStart()
		{
			IF_COUT{ std::cout << "destructing State: GameStart" << std::endl; }
		}

		void OnEnter(ObjData& objData, GameData& gameData) override
		{
			objData.position = { 300.0f, 650.0f };
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			frameCount++;
			
			if (frameCount >= 62)
			{
				nextState = State::CreateState<PlayerIdle>();
			}
		}
	};
}