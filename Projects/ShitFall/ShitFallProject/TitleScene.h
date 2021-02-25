#pragma once
#include "Scene.h"
#include "GameObjTree.h"
#include "DecalLoader.h"
#include "TitleDecalPath.h"

namespace RB
{
	class TitleScene : public Scene
	{
	private:
		DecalLoader decalLoader;
		

	public:
		TitleScene()
		{
			std::cout << "constructing TitleScene" << std::endl;

			decalLoader.LoadSprites<TitleDecalPath>();
			decalLoader.LoadDecals();
		}

		~TitleScene()
		{
			std::cout << "destructing TitleScene" << std::endl;
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
			background.controllerType = ControllerType::NONE;

			title.width = 500.0f;
			title.height = 180.0f;
			title.objType = GameObjType::title;
			title.controllerType = ControllerType::TITLE_CONTROLLER;

			pressEnter.width = 300.0f;
			pressEnter.height = 90.0f;
			pressEnter.objType = GameObjType::press_enter;
			pressEnter.controllerType = ControllerType::PRESS_ENTER_CONTROLLER;

			dummy.width = 50.0f;
			dummy.height = 80.0f;
			dummy.objType = GameObjType::dummy;
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
			GameObj* background = objTree.GetObjType(GameObjType::background);
			GameObj* title = objTree.GetObjType(GameObjType::title);
			GameObj* pressEnter = objTree.GetObjType(GameObjType::press_enter);
			GameObj* dummy = objTree.GetObjType(GameObjType::dummy);

			background->Render(ptrEngine, decalLoader.GetDecal((int)TitleSpriteType::background), RenderOffsetType::NONE);
			title->Render(ptrEngine, decalLoader.GetDecal((int)TitleSpriteType::title_line500x180), RenderOffsetType::CENTER_CENTER);
			pressEnter->Render(ptrEngine, decalLoader.GetDecal((int)TitleSpriteType::press_enter300x90), RenderOffsetType::CENTER_CENTER);
			dummy->Render(ptrEngine, decalLoader.GetDecal((int)TitleSpriteType::playerbox_green), RenderOffsetType::BOTTOM_CENTER);
		}

		void RenderStates(olc::PixelGameEngine* ptrEngine) override
		{

		}
	};
}