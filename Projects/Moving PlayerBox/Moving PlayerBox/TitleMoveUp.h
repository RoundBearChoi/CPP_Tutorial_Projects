#pragma once
#include "State.h"

namespace RB
{
	class TitleMoveUp : public State
	{
	private:
		int frameCount = 0;

	public:
		TitleMoveUp()
		{
			std::cout << "constructing State: TitleMoveUp" << std::endl;
		}

		~TitleMoveUp()
		{
			std::cout << "destructing State: TitleMoveUp" << std::endl;
		}

		void UpdateState(ObjData& objData, GameObjTree* tree, const GameData& gameData) override
		{
			frameCount++;
			objData.position.y -= 10.0f;

			if (frameCount >= 31)
			{
				changeSceneIndex = 2; // game scene index is 2
			}
		}
	};
}