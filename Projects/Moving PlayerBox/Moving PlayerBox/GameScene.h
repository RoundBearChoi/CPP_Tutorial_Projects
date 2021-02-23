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
			ObjSpecs background(GameObjType::background, ControllerType::NONE);
			ObjSpecs player(GameObjType::player, ControllerType::PLAYER_CONTROLLER);
			ObjSpecs shitgroup(GameObjType::shitgroup, ControllerType::SHIT_CONTROLLER_GENERATOR);

			objTree.CreateObj(background);
			objTree.CreateObj(player);
			objTree.CreateObj(shitgroup);
		}

		void UpdateScene(olc::PixelGameEngine* ptrEngine, const GameData& gameData) override
		{
			objTree.UpdateAll(gameData);
		}

		void RenderScene(olc::PixelGameEngine* ptrEngine) override
		{
			GameObj* background = objTree.GetObjType(GameObjType::background);
			GameObj* playerBox = objTree.GetObjType(GameObjType::player);
			GameObj* playerPoint = objTree.GetObjType(GameObjType::player);
			GameObj* shitgroup = objTree.GetObjType(GameObjType::shitgroup);

			background->Render(ptrEngine, decalLoader.GetDecal((int)SpriteType::background), RenderOffsetType::NONE);
			playerBox->Render(ptrEngine, decalLoader.GetDecal((int)SpriteType::playerbox_green), RenderOffsetType::BOTTOM_CENTER);
			playerPoint->Render(ptrEngine, decalLoader.GetDecal((int)SpriteType::diamond_red), RenderOffsetType::CENTER_CENTER);
			shitgroup->Render(ptrEngine, decalLoader.GetDecal((int)SpriteType::redbox_10x10), RenderOffsetType::CENTER_CENTER);
		}
	};
}