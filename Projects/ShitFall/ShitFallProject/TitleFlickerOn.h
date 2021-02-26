#pragma once
#include "State.h"
#include "TitleSpriteType.h"

namespace RB
{
	class TitleFlickerOn : public State
	{
	public:
		TitleFlickerOn()
		{
			IF_COUT{ std::cout << "constructing State: TitleFlickerOn" << std::endl; }

			stateAnimation.SetParams((int)TitleSpriteType::pressenter, 300, 90, 1, 1, 1, false);
		}

		~TitleFlickerOn()
		{
			IF_COUT{ std::cout << "destructing State: TitleFlickerOn" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			objData.position = { 300.0f, 350.0f };

			frameCount++;

			if (frameCount >= 90)
			{
				frameCount = 0;
				objData.nextStateIndex = (int)TitleStateType::FLICKER_OFF;
			}
		}
	};
}