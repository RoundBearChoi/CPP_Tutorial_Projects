#pragma once
#include "Scene.h"
#include "DecalLoader.h"
#include "GameDecalPath.h"
#include "DevSettings.h"

namespace RB
{
	class GameScene : public Scene
	{
	private:
		DecalLoader decalLoader;
		
	public:
		GameScene()
		{
			IF_COUT{ std::cout << "constructing GameScene" << std::endl; }
			
			decalLoader.LoadSprites<GameDecalPath>();
			decalLoader.LoadDecals();
		}

		~GameScene()
		{
			IF_COUT{ std::cout << "destructing GameScene" << std::endl; }
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
			background.controllerType = ControllerType::TITLE_UI_CONTROLLER;
			background.initialStateIndex = (int)UIElementStateType::BACKGROUND_IDLE;
			
			player.width = 50.0f;
			player.height = 80.0f;
			player.objType = GameObjType::player;
			player.offsetType = OffsetType::BOTTOM_CENTER;
			player.debugDecalIndex = (int)GameSpriteType::playerbox_green;
			player.controllerType = ControllerType::PLAYER_CONTROLLER;
			player.initialStateIndex = (int)PlayerStateType::GAME_START;

			shitgroup.width = 0.0f;
			shitgroup.height = 0.0f;
			shitgroup.objType = GameObjType::shitgroup;
			shitgroup.offsetType = OffsetType::CENTER_CENTER;
			shitgroup.debugDecalIndex = (int)GameSpriteType::redbox_10x10;
			shitgroup.controllerType = ControllerType::SHIT_CONTROLLER;
			shitgroup.initialStateIndex = (int)ShitStateType::GENERATOR;

			objList.CreateObj(background);
			objList.CreateObj(player);
			objList.CreateObj(shitgroup);
		}

		void UpdateScene(olc::PixelGameEngine* ptrEngine, GameData& gameData) override
		{
			objList.UpdateObjs(gameData);
		}

		void RenderObjs(olc::PixelGameEngine* ptrEngine) override
		{
			objList.RenderObjs(ptrEngine, &decalLoader);

			//GameObj* background = objList.GetObj(0);
			//background->Render(ptrEngine, decalLoader.GetDecal(background->data.debugDecalIndex));
		}

		void RenderStates(olc::PixelGameEngine* ptrEngine) override
		{
			objList.RenderStates(ptrEngine, &decalLoader);
		}
	};
}