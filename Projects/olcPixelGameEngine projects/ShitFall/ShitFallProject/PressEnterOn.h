#pragma once
#include "State.h"
#include "TitleSpriteType.h"

namespace RB
{
	class PressEnterOff;

	class PressEnterOn : public State
	{
	public:
		PressEnterOn()
		{
			IF_COUT{ std::cout << "constructing State: TitleFlickerOn" << std::endl; }

			animationController.SetParams((int)TitleSpriteType::pressenter, 300, 90, 1, 1, 1, false);
		}

		~PressEnterOn()
		{
			IF_COUT{ std::cout << "destructing State: TitleFlickerOn" << std::endl; }
		}

		void OnEnter(ObjData& objData, GameData& gameData) override
		{
			objData.position = { 300.0f, 350.0f };
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			if (gameData.startGame)
			{
				nextState = State::CreateState<PressEnterOff>();
			}
			else
			{
				frameCount++;

				if (frameCount >= 90)
				{
					frameCount = 0;
					nextState = State::CreateState<PressEnterOff>();
				}
			}
		}
	};
}