#pragma once
#include "State.h"
#include "TitleSpriteType.h"

namespace RB
{
	class TitleFlickerOff : public State
	{
	public:
		TitleFlickerOff(ObjData& objData)
		{
			IF_COUT{ std::cout << "constructing State: TitleFlickerOff" << std::endl; }

			objData.position = { 300.0f, 350.0f };
		}

		~TitleFlickerOff()
		{
			IF_COUT{ std::cout << "destructing State: TitleFlickerOff" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			if (!gameData.startGame)
			{
				frameCount++;

				if (frameCount >= 55)
				{
					frameCount = 0;
					//objData.nextStateIndex = (int)UIElementStateType::FLICKER_ON;
				}
			}
		}
	};
}