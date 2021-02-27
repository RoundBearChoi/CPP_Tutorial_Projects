#pragma once
#include "State.h"
#include "TitleSpriteType.h"

namespace RB
{
	class TitleFlickerOn : public State
	{
	public:
		TitleFlickerOn(ObjData& objData)
		{
			IF_COUT{ std::cout << "constructing State: TitleFlickerOn" << std::endl; }

			stateAnimation.SetParams((int)TitleSpriteType::pressenter, 300, 90, 1, 1, 1, false);

			objData.position = { 300.0f, 350.0f };
		}

		~TitleFlickerOn()
		{
			IF_COUT{ std::cout << "destructing State: TitleFlickerOn" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			if (gameData.startGame)
			{
				objData.nextStateIndex = (int)UIElementStateType::FLICKER_OFF;
			}
			else
			{
				frameCount++;

				if (frameCount >= 90)
				{
					frameCount = 0;
					objData.nextStateIndex = (int)UIElementStateType::FLICKER_OFF;
				}
			}
		}
	};
}