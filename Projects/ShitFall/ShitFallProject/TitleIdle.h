#pragma once
#include "State.h"
#include "StateType.h"
#include "TitleSpriteType.h"

namespace RB
{
	class TitleMoveDown;

	class TitleIdle : public State
	{
	public:
		TitleIdle(ObjData& objData)
		{
			IF_COUT{ std::cout << "constructing State: TitleIdle" << std::endl; }

			stateAnimation.SetParams((int)TitleSpriteType::shitfall_title, 500, 180, 1, 1, 1, false);

			objData.position = { 300.0f, 160.0f };
		}

		~TitleIdle()
		{
			IF_COUT{ std::cout << "destructing State: TitleIdle" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			if (gameData.startGame)
			{
				nextState = State::CreateState<TitleMoveDown>(objData);
			}
		}
	};
}