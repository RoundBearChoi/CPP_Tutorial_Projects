#pragma once
#include "Scene.h"
#include "DecalLoader.h"
#include "TitleDecalPath.h"
#include "DevSettings.h"

#include "BackgroundIdle.h"
#include "TitleIdle.h"
#include "TitleMoveDown.h"
#include "TitleMoveUp.h"
#include "TitleFlickerOn.h"
#include "PlayerDummy.h"

namespace RB
{
	class TitleScene : public Scene
	{
	public:
		TitleScene(DecalLoader* _decalLoader)
		{
			IF_COUT{ std::cout << "constructing TitleScene" << std::endl; }

			decalLoader = _decalLoader;
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
			background.decalIndex = (int)TitleSpriteType::background;
			
			title.width = 500.0f;
			title.height = 180.0f;
			title.objType = GameObjType::title;
			title.offsetType = OffsetType::CENTER_CENTER;
			title.decalIndex = (int)TitleSpriteType::title_line500x180;

			pressEnter.width = 300.0f;
			pressEnter.height = 90.0f;
			pressEnter.objType = GameObjType::press_enter;
			pressEnter.offsetType = OffsetType::CENTER_CENTER;
			pressEnter.decalIndex = (int)TitleSpriteType::press_enter300x90;
			
			dummy.width = 50.0f;
			dummy.height = 80.0f;
			dummy.objType = GameObjType::dummy;
			dummy.offsetType = OffsetType::BOTTOM_CENTER;
			dummy.decalIndex = (int)TitleSpriteType::playerbox_green;
			
			objList.CreateObj<BackgroundIdle>(background);
			objList.CreateObj<TitleIdle>(title);
			objList.CreateObj<TitleFlickerOn>(pressEnter);
			objList.CreateObj<PlayerDummy>(dummy);
		}

		void UpdateScene(olc::PixelGameEngine* ptrEngine, GameData& gameData) override
		{
			objList.UpdateObjs(gameData);
		}

		void RenderObjs(olc::PixelGameEngine* ptrEngine) override
		{
			objList.RenderObjs(ptrEngine, decalLoader);

			//GameObj* background = objList.GetObj(0);
			//background->Render(ptrEngine, decalLoader->GetDecal(background->data.decalIndex));
		}

		void RenderStates(olc::PixelGameEngine* ptrEngine) override
		{
			objList.RenderStates(ptrEngine, decalLoader);
		}
	};
}