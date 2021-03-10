#pragma once
#include "State.h"

namespace RB
{
	class TitleMoveUp : public State
	{
	public:
		TitleMoveUp()
		{
			IF_COUT{ std::cout << "constructing State: TitleMoveUp" << std::endl; }

			animationController.SetParams((int)TitleSpriteType::shitfall_title, 500, 180, 1, 1, 1, false);
		}

		~TitleMoveUp()
		{
			IF_COUT{ std::cout << "destructing State: TitleMoveUp" << std::endl; }
		}

		void OnEnter(ObjData& objData, GameData& gameData) override
		{

		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			frameCount++;
			objData.position.y -= 10.0f;

			if (frameCount >= 31)
			{
				gameData.nextSceneType = SceneType::GAME_SCENE;
			}
		}
	};
}