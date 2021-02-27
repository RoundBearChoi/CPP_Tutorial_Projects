#pragma once
#include "State.h"
#include "DevSettings.h"
#include "GameSpriteType.h"

namespace RB
{
	class YesOrNo : public State
	{
	private:
		float speed = 16.5f;

	public:
		YesOrNo(ObjData& objData)
		{
			IF_COUT{ std::cout << "constructing State: YesOrNo" << std::endl; }

			stateAnimation.SetParams((int)GameSpriteType::shitrestart, 460, 330, 1, 1, 1, false);

			objData.position = { 300.0f, -165.0f };
		}

		~YesOrNo()
		{
			IF_COUT{ std::cout << "destructing State: YesOrNo" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			//start slowing down
			if (frameCount > 23)
			{
				speed -= 0.865f;
			}

			if (frameCount < 55)
			{
				frameCount++;
				objData.position.y += speed;
			}
		}
	};
}