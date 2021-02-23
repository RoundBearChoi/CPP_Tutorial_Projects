#pragma once
#include "State.h"

namespace RB
{
	class TitleMoveDown : public State
	{
	private:
		int frameCount = 0;
		float speed = 3.0f;

	public:
		TitleMoveDown()
		{
			std::cout << "constructing State: TitleMoveDown" << std::endl;
		}

		~TitleMoveDown()
		{
			std::cout << "destructing State: TitleMoveDown" << std::endl;
		}

		void UpdateState(ObjData& objData, const GameData& gameData) override
		{
			frameCount++;
			objData.position.y += speed;

			speed -= 0.1f;

			if (frameCount >= 30)
			{
				nextStateIndex = (int)TitleStateType::MOVE_UP;
			}
		}
	};
}