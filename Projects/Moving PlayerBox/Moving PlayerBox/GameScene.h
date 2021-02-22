#pragma once
#include "Scene.h"
#include "GameDecalLoader.h"
#include "GameObjTree.h"
#include "SpritePath.h"

namespace RB
{
	class GameScene : public Scene
	{
	private:
		GameDecalLoader decalLoader;
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
			objTree.CreateObj(GameObjType::background);
			objTree.CreateObj(GameObjType::player, ControllerType::PLAYER_CONTROLLER);
			objTree.CreateObj(GameObjType::shitgroup, ControllerType::SHIT_GENERATOR_CONTROLLER);
		}

		void UpdateScene(olc::PixelGameEngine* ptrEngine, const GameData& gameData) override
		{
			objTree.UpdateAll(gameData);
		}

		void RenderScene(olc::PixelGameEngine* ptrEngine) override
		{
			objTree.GetObjType(GameObjType::background)->Render(ptrEngine, decalLoader.GetDecal((int)SpriteType::background), RenderOffsetType::NONE);
			objTree.GetObjType(GameObjType::player)->Render(ptrEngine, decalLoader.GetDecal((int)SpriteType::playerbox_green), RenderOffsetType::BOTTOM_CENTER);
			objTree.GetObjType(GameObjType::player)->Render(ptrEngine, decalLoader.GetDecal((int)SpriteType::diamond_red), RenderOffsetType::CENTER_CENTER);
			objTree.GetObjType(GameObjType::shitgroup)->Render(ptrEngine, decalLoader.GetDecal((int)SpriteType::redbox_10x10), RenderOffsetType::CENTER_CENTER);
		}
	};
}