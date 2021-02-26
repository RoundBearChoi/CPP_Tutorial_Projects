#pragma once
#include "State.h"
#include "StateType.h"
#include "TitleSpriteType.h"

namespace RB
{
	class TitleIdle : public State
	{
	public:
		TitleIdle()
		{
			IF_COUT{ std::cout << "constructing State: TitleIdle" << std::endl; }

			stateAnimation.SetParams((int)TitleSpriteType::shitfall_title, 500, 180, 1, 1, 1, false);
		}

		~TitleIdle()
		{
			IF_COUT{ std::cout << "destructing State: TitleIdle" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			objData.position = { 300.0f, 160.0f };

			if (gameData.startGame)
			{
				objData.nextStateIndex = (int)UIElementStateType::MOVE_DOWN;
			}
		}
	};
}