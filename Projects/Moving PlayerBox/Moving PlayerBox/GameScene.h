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
			objTree.CreateObj((int)GameObjType::background);
			objTree.CreateObj((int)GameObjType::player, (int)ControllerType::PLAYER_CONTROLLER);
			objTree.CreateObj((int)GameObjType::shitgroup, (int)ControllerType::SHIT_GENERATOR_CONTROLLER);
		}

		void UpdateScene(olc::PixelGameEngine* ptrEngine, const GameData& gameData) override
		{
			objTree.UpdateAll(gameData);
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