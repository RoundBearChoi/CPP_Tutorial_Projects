#pragma once
#include "Scene.h"
#include "TitleDecalLoader.h"

namespace RB
{
	class TitleScene : public Scene
	{
	private:
		int frameCount = 0;
		TitleDecalLoader decalLoader;

	public:
		TitleScene()
		{
			std::cout << "constructing TitleScene" << std::endl;
		}

		~TitleScene()
		{
			std::cout << "destructing TitleScene" << std::endl;
		}

		void InitScene() override
		{
			ObjSpecs background(GameObjType::background, ControllerType::NONE);
			ObjSpecs title(GameObjType::title, ControllerType::TITLE_CONTROLLER);
			ObjSpecs dummy(GameObjType::dummy, ControllerType::DUMMY_PLAYER_CONTROLLER);

			objTree.CreateObj(background);
			objTree.CreateObj(title);
			objTree.CreateObj(dummy);
		}

		void UpdateScene(olc::PixelGameEngine* ptrEngine, const GameData& gameData) override
		{
			objTree.UpdateAll(gameData);

			frameCount++;
		}

		void RenderScene(olc::PixelGameEngine* ptrEngine) override
		{
			GameObj* background = objTree.GetObjType(GameObjType::background);
			GameObj* title = objTree.GetObjType(GameObjType::title);
			GameObj* dummy = objTree.GetObjType(GameObjType::dummy);

			background->Render(ptrEngine, decalLoader.GetDecal((int)TitleSpriteType::background), RenderOffsetType::NONE);
			title->Render(ptrEngine, decalLoader.GetDecal((int)TitleSpriteType::title_line500x180), RenderOffsetType::CENTER_CENTER);
			dummy->Render(ptrEngine, decalLoader.GetDecal((int)TitleSpriteType::playerbox_green), RenderOffsetType::BOTTOM_CENTER);
		}
	};
}