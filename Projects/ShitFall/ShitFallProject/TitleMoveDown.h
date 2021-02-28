#pragma once
#include "State.h"

namespace RB
{
	class TitleMoveUp;

	class TitleMoveDown : public State
	{
	private:
		float speed = 3.0f;

	public:
		TitleMoveDown(ObjData& objData)
		{
			IF_COUT{ std::cout << "constructing State: TitleMoveDown" << std::endl; }

			stateAnimation.SetParams((int)TitleSpriteType::shitfall_title, 500, 180, 1, 1, 1, false);
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
				nextState = State::CreateState<TitleMoveUp>(objData);
			}
		}
	};
}