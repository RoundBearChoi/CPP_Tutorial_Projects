#pragma once
#include "State.h"
#include "StateType.h"

namespace RB
{
	class PlayerGameStart : public State
	{
	public:
		PlayerGameStart(ObjData& objData)
		{
			IF_COUT
			{
				std::cout << std::endl;
				std::cout << "constructing State: GameStart" << std::endl;
			}

			stateAnimation.SetParams((int)GameSpriteType::idle_sheet, 300, 80, 6, 1, 6, false);
			stateAnimation.SetDelayTime(500);

			objData.position = { 300.0f, 650.0f };
		}

		~PlayerGameStart()
		{
			IF_COUT{ std::cout << "destructing State: GameStart" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			frameCount++;
			
			if (frameCount >= 50)
			{
				objData.nextStateIndex = (int)PlayerStateType::IDLE;
			}
		}
	};
}