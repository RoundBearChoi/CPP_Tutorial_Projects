#pragma once
#include "State.h"
#include "DevSettings.h"
#include "TitleSpriteType.h"

namespace RB
{
	class PlayerDummy : public State
	{
	public:
		PlayerDummy()
		{
			IF_COUT{ std::cout << "constructing State: PlayerDummy" << std::endl; }

			stateAnimation.SetParams((int)TitleSpriteType::idle_sheet, 300, 80, 6, 1, 6, false);
			stateAnimation.SetDelayTime(500);
		}

		~PlayerDummy()
		{
			IF_COUT{ std::cout << "destructing State: PlayerDummy" << std::endl; }
		}

		void OnEnter(ObjData& objData, GameData& gameData) override
		{
			objData.position = { 300.0f, 650.0f };
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			
		}
	};
}