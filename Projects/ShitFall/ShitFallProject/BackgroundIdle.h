#pragma once
#include "State.h"
#include "StateType.h"
#include "TitleSpriteType.h"

namespace RB
{
	class BackgroundIdle : public State
	{
	public:
		BackgroundIdle()
		{
			IF_COUT{ std::cout << "constructing State: BackgroundIdle" << std::endl; }
		}

		~BackgroundIdle()
		{
			IF_COUT{ std::cout << "destructing State: BackgroundIdle" << std::endl; }
		}

		void OnEnter(ObjData& objData, GameData& gameData) override
		{

		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{

		}
	};
}