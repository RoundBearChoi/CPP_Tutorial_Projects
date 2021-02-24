#pragma once
#include "State.h"

namespace RB
{
	class TitleMoveUp : public State
	{
	public:
		TitleMoveUp()
		{
			std::cout << "constructing State: TitleMoveUp" << std::endl;
		}

		~TitleMoveUp()
		{
			std::cout << "destructing State: TitleMoveUp" << std::endl;
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