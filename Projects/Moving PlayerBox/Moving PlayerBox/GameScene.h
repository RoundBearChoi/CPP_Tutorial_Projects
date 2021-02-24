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
			ObjSpecs background;
			ObjSpecs player;
			ObjSpecs shitgroup;

			background.width = 600.0f;
			background.height = 700.0f;
			background.objType = GameObjType::background;
			background.controllerType = ControllerType::NONE;

			player.width = 50.0f;
			player.height = 80.0f;
			player.objType = GameObjType::player;
			player.controllerType = ControllerType::PLAYER_CONTROLLER;

			shitgroup.width = 0.0f;
			shitgroup.height = 0.0f;
			shitgroup.objType = GameObjType::shitgroup;
			shitgroup.controllerType = ControllerType::SHIT_CONTROLLER_GENERATOR;

			objTree.CreateObj(background);
			objTree.CreateObj(player);
			objTree.CreateObj(shitgroup);
		}

		void UpdateScene(olc::PixelGameEngine* ptrEngine, GameData& gameData) override
		{
			objTree.UpdateAll(gameData);
		}

		void RenderScene(olc::PixelGameEngine* ptrEngine) override
		{
			GameObj* background = objTree.GetObjType(GameObjType::background);
			GameObj* playerBox = objTree.GetObjType(GameObjType::player);
			GameObj* shitgroup = objTree.GetObjType(GameObjType::shitgroup);

			background->Render(ptrEngine, decalLoader.GetDecal((int)GameSpriteType::background), RenderOffsetType::NONE);
			playerBox->Render(ptrEngine, decalLoader.GetDecal((int)GameSpriteType::playerbox_green), RenderOffsetType::BOTTOM_CENTER);
			shitgroup->Render(ptrEngine, decalLoader.GetDecal((int)GameSpriteType::redbox_10x10), RenderOffsetType::CENTER_CENTER);

			std::vector<GameObj*>& shits = shitgroup->GetChildren();

			for (int i = 0; i < shits.size(); i++)
			{
				shits[i]->Render(ptrEngine, decalLoader.GetDecal((int)GameSpriteType::shit_box32x32), RenderOffsetType::CENTER_CENTER);
			}
		}
	};
}