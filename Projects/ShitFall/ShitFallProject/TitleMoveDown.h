#pragma once
#include "State.h"

namespace RB
{
	class TitleMoveDown : public State
	{
	private:
		float speed = 3.0f;

	public:
		TitleMoveDown()
		{
			IF_COUT{ std::cout << "constructing State: TitleMoveDown" << std::endl; }
		}

		~TitleMoveDown()
		{
			IF_COUT{ std::cout << "destructing State: TitleMoveDown" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			frameCount++;
			objData.position.y += speed;

			speed -= 0.1f;

			if (frameCount >= 30)
			{
				objData.nextStateIndex = (int)TitleStateType::MOVE_UP;
			}
		}
	};
}