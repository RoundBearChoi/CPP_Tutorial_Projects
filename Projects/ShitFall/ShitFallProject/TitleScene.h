#pragma once
#include "Scene.h"
#include "GameObjTree.h"
#include "DecalLoader.h"
#include "TitleDecalPath.h"
#include "DevSettings.h"

namespace RB
{
	class TitleScene : public Scene
	{
	private:
		DecalLoader decalLoader;
		
	public:
		TitleScene()
		{
			IF_COUT{ std::cout << "constructing TitleScene" << std::endl; }

			decalLoader.LoadSprites<TitleDecalPath>();
			decalLoader.LoadDecals();
		}

		~TitleScene()
		{
			IF_COUT{ std::cout << "destructing TitleScene" << std::endl; }
		}

		void InitScene() override
		{
			ObjSpecs background;
			ObjSpecs title;
			ObjSpecs pressEnter;
			ObjSpecs dummy;
			
			background.width = 600.0f;
			background.height = 700.0f;
			background.objType = GameObjType::background;
			background.offsetType = OffsetType::NONE;
			background.debugDecalIndex = (int)TitleSpriteType::background;
			background.controllerType = ControllerType::NONE;
			
			title.width = 500.0f;
			title.height = 180.0f;
			title.objType = GameObjType::title;
			title.offsetType = OffsetType::CENTER_CENTER;
			title.debugDecalIndex = (int)TitleSpriteType::title_line500x180;
			title.controllerType = ControllerType::TITLE_CONTROLLER;
			
			pressEnter.width = 300.0f;
			pressEnter.height = 90.0f;
			pressEnter.objType = GameObjType::press_enter;
			pressEnter.offsetType = OffsetType::CENTER_CENTER;
			pressEnter.debugDecalIndex = (int)TitleSpriteType::press_enter300x90;
			pressEnter.controllerType = ControllerType::PRESS_ENTER_CONTROLLER;
			
			dummy.width = 50.0f;
			dummy.height = 80.0f;
			dummy.objType = GameObjType::dummy;
			dummy.offsetType = OffsetType::BOTTOM_CENTER;
			dummy.debugDecalIndex = (int)TitleSpriteType::playerbox_green;
			dummy.controllerType = ControllerType::DUMMY_PLAYER_CONTROLLER;
			
			objTree.CreateObj(background);
			objTree.CreateObj(title);
			objTree.CreateObj(pressEnter);
			objTree.CreateObj(dummy);
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

		}
	};
}