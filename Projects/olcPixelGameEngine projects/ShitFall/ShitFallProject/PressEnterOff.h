#pragma once
#include "State.h"
#include "TitleSpriteType.h"

namespace RB
{
	class PressEnterOn;

	class PressEnterOff : public State
	{
	public:
		PressEnterOff()
		{
			IF_COUT{ std::cout << "constructing State: TitleFlickerOff" << std::endl; }
		}

		~PressEnterOff()
		{
			IF_COUT{ std::cout << "destructing State: TitleFlickerOff" << std::endl; }
		}

		void OnEnter(ObjData& objData, GameData& gameData) override
		{
			objData.position = { 300.0f, 350.0f };
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			if (!gameData.startGame)
			{
				frameCount++;

				if (frameCount >= 55)
				{
					frameCount = 0;
					nextState = State::CreateState<PressEnterOn>();
				}
			}
		}
	};
}