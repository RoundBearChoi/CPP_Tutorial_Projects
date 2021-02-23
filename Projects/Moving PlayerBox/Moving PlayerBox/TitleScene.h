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
		GameObjTree objTree;

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

			objTree.CreateObj(background);
			objTree.CreateObj(title);
		}

		void UpdateScene(olc::PixelGameEngine* ptrEngine, const GameData& gameData) override
		{
			objTree.UpdateAll(gameData);

			frameCount++;

			if (frameCount >= 2 * 120)
			{
				nNextSceneQueue = 2; //gamescene index is 2
			}
		}

		void RenderScene(olc::PixelGameEngine* ptrEngine) override
		{
			GameObj* background = objTree.GetObjType(GameObjType::background);
			GameObj* title = objTree.GetObjType(GameObjType::title);

			background->Render(ptrEngine, decalLoader.GetDecal((int)TitleSpriteType::background), RenderOffsetType::NONE);
			title->Render(ptrEngine, decalLoader.GetDecal((int)TitleSpriteType::title_line500x180), RenderOffsetType::NONE);
		}
	};
}