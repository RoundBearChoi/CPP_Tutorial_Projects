#pragma once
#include "Scene.h"
#include "GameDecalLoader.h"
#include "GameObjTree.h"
#include "SpriteType.h"

namespace RB
{
	class GameScene : public Scene
	{
	private:
		GameDecalLoader gameDecalLoader;
		GameObjTree objTree;

	public:
		GameScene()
		{
			std::cout << "constructing GameScene" << std::endl;
		}

		~GameScene()
		{
			std::cout << "destructing GameScene" << std::endl;
		}

		void InitScene() override
		{
			objTree.CreateObj((int)GameObjType::player);
			objTree.CreateObj((int)GameObjType::background);
			objTree.CreateObj((int)GameObjType::shitgroup);

			objTree.GetObjType((int)GameObjType::player)->SetController((int)ControllerType::PLAYER_CONTROLLER);
			objTree.GetObjType((int)GameObjType::shitgroup)->SetController((int)ControllerType::SHIT_GENERATOR_CONTROLLER);
		}

		void UpdateScene(olc::PixelGameEngine* ptrEngine, const GameData& gameData) override
		{
			objTree.UpdateAll(gameData);

			//if (input.ESCPressed(ptrEngine))
			//{
			//	bQuit = true;
			//	std::cout << std::endl;
			//	std::cout << "---quit triggered---" << std::endl;
			//}
		}

		void RenderScene(olc::PixelGameEngine* ptrEngine) override
		{
			objTree.GetObjType((int)GameObjType::background)->Render(ptrEngine, gameDecalLoader.GetDecal((int)GameSpriteType::background), RenderOffsetType::NONE);
			objTree.GetObjType((int)GameObjType::player)->Render(ptrEngine, gameDecalLoader.GetDecal((int)GameSpriteType::playerbox_green), RenderOffsetType::BOTTOM_CENTER);
			objTree.GetObjType((int)GameObjType::player)->Render(ptrEngine, gameDecalLoader.GetDecal((int)GameSpriteType::diamond_red), RenderOffsetType::CENTER_CENTER);
			objTree.GetObjType((int)GameObjType::shitgroup)->Render(ptrEngine, gameDecalLoader.GetDecal((int)GameSpriteType::redbox_10x10), RenderOffsetType::CENTER_CENTER);

		}
	};
}