#pragma once
#include "State.h"

namespace RB
{
	class ShitSplash : public State
	{
	public:
		ShitSplash()
		{
			IF_COUT{ std::cout << "constructing State: ShitSplash" << std::endl; }

			stateAnimation.SetParams((int)GameSpriteType::upsplash_sheet, 592, 74, 8, 1, 8, false);
			stateAnimation.SetDelayTime(13);
			stateAnimation.SetPlayOnce(true);
		}

		~ShitSplash()
		{
			IF_COUT
			{
				std::cout << std::endl;
				std::cout << "destructing State: ShitSplash" << std::endl;
			}
		}

		void OnEnter(ObjData& objData, GameData& gameData) override
		{
			//change obj size
			objData.size.x = 87.0f;
			objData.size.y = 87.0f;
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			if (stateAnimation.OnLastAnimationFrame())
			{

				deleteObj = true;
			}
			
		}
	};
}