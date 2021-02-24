#pragma once
#include "State.h"
#include "StateType.h"

namespace RB
{
	class TitleIdle : public State
	{
	public:
		TitleIdle()
		{
			std::cout << "constructing State: TitleIdle" << std::endl;
		}

		~TitleIdle()
		{
			std::cout << "destructing State: TitleIdle" << std::endl;
		}

		void UpdateState(ObjData& objData, const GameData& gameData) override
		{
			objData.position = { 300.0f, 160.0f };

			if (gameData.startGame)
			{
				nextStateIndex = (int)TitleStateType::MOVE_DOWN;
			}
		}
	};
}