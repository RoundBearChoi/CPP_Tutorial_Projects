#pragma once
#include "State.h"

namespace RB
{
	class TitleMoveUp : public State
	{
	public:
		TitleMoveUp(ObjData& objData)
		{
			IF_COUT{ std::cout << "constructing State: TitleMoveUp" << std::endl; }

			stateAnimation.SetParams((int)TitleSpriteType::shitfall_title, 500, 180, 1, 1, 1, false);
		}

		~TitleMoveUp()
		{
			IF_COUT{ std::cout << "destructing State: TitleMoveUp" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			frameCount++;
			objData.position.y -= 10.0f;

			if (frameCount >= 31)
			{
				gameData.nextSceneIndex = 2;
			}
		}
	};
}