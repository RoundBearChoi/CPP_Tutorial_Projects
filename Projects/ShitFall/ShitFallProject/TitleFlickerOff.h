#pragma once
#include "State.h"
#include "TitleSpriteType.h"

namespace RB
{
	class TitleFlickerOff : public State
	{
	public:
		TitleFlickerOff()
		{
			IF_COUT{ std::cout << "constructing State: TitleFlickerOff" << std::endl; }
		}

		~TitleFlickerOff()
		{
			IF_COUT{ std::cout << "destructing State: TitleFlickerOff" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			objData.position = { 300.0f, 350.0f };

			frameCount++;

			if (frameCount >= 55)
			{
				frameCount = 0;
				objData.nextStateIndex = (int)UIElementStateType::FLICKER_ON;
			}
		}
	};
}