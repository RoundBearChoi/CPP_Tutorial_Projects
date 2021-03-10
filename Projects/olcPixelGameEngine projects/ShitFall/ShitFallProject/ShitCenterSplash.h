#pragma once
#include "State.h"

namespace RB
{
	class ShitCenterSplash : public State
	{
	public:
		ShitCenterSplash()
		{
			IF_COUT{ std::cout << "constructing State: ShitCenterSplash" << std::endl; }

				//same as shitmovedown on first render
			animationController.SetParams((int)GameSpriteType::shit, 37, 37, 1, 1, 1, false);
		}

		~ShitCenterSplash()
		{
			IF_COUT
			{
				std::cout << std::endl;
				std::cout << "destructing State: ShitCenterSplash" << std::endl;
			}
		}

		void OnEnter(ObjData& objData, GameData& gameData) override
		{
			//change tag (prevent slowmo)
			//objData.objTag = ObjTag::NONE;

			//change obj size
			objData.size.x = 420.0f;
			objData.size.y = 420.0f;

			//set new spritesheet
			animationController.SetParams((int)GameSpriteType::centersplash_sheet, 880, 220, 4, 1, 4, false);
			animationController.data.transitionDelay = (int)TransitionDelayTable::SHIT_CENTERSPLASH;
			animationController.data.playOnce = true;
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			if (animationController.OnLastAnimationFrame())
			{
				deleteObj = true;
			}
		}
	};
}