#pragma once
#include "State.h"

namespace RB
{
	class ShitUpSplash : public State
	{
	public:
		ShitUpSplash()
		{
			IF_COUT{ std::cout << "constructing State: ShitSplash" << std::endl; }

			stateAnimation.SetParams((int)GameSpriteType::upsplash_sheet_2, 720, 120, 6, 1, 6, false);
			stateAnimation.SetDelayTime(25);
			stateAnimation.SetPlayOnce(true);
		}

		~ShitUpSplash()
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
			objData.size.x = 110.0f;
			objData.size.y = 110.0f;
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