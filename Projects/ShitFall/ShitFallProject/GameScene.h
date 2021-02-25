#pragma once
#include "Scene.h"
#include "GameObjTree.h"
#include "DecalLoader.h"
#include "GameDecalPath.h"

namespace RB
{
	class GameScene : public Scene
	{
	private:
		DecalLoader decalLoader;
		
		
	public:
		GameScene()
		{
			std::cout << "constructing GameScene" << std::endl;

			decalLoader.LoadSprites<GameDecalPath>();
			decalLoader.LoadDecals();
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
			background.offsetType = OffsetType::NONE;
			background.debugDecalIndex = (int)GameSpriteType::background;
			background.controllerType = ControllerType::NONE;
			
			player.width = 50.0f;
			player.height = 80.0f;
			player.objType = GameObjType::player;
			player.offsetType = OffsetType::BOTTOM_CENTER;
			player.debugDecalIndex = (int)GameSpriteType::playerbox_green;
			player.controllerType = ControllerType::PLAYER_CONTROLLER;
			
			shitgroup.width = 0.0f;
			shitgroup.height = 0.0f;
			shitgroup.objType = GameObjType::shitgroup;
			shitgroup.offsetType = OffsetType::CENTER_CENTER;
			shitgroup.debugDecalIndex = (int)GameSpriteType::redbox_10x10;
			shitgroup.controllerType = ControllerType::SHIT_CONTROLLER_GENERATOR;
			
			objTree.CreateObj(background);
			objTree.CreateObj(player);
			objTree.CreateObj(shitgroup);
		}

		void UpdateScene(olc::PixelGameEngine* ptrEngine, GameData& gameData) override
		{
			objTree.UpdateObjs(gameData);
		}

		void RenderObjs(olc::PixelGameEngine* ptrEngine) override
		{
			objTree.RenderObjs(ptrEngine, &decalLoader);
		}

		void RenderStates(olc::PixelGameEngine* ptrEngine) override
		{
			objTree.RenderStates(ptrEngine, &decalLoader);
		}
	};
}