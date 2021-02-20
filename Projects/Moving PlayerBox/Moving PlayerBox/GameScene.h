#pragma once
#include "Scene.h"
#include "DecalLoader.h"
#include "Input.h"
#include "SceneObjList.h"
#include "PlayerController.h"

namespace RB
{
	class GameScene : public Scene
	{
	private:
		DecalLoader decalLoader;
		Input input;
		SceneObjList sceneObjList;

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
			decalLoader.LoadAll();

			sceneObjList.CreateObj("player");
			sceneObjList.CreateObj("background");

			sceneObjList.GetObj(0)->SetController<PlayerController>();
			sceneObjList.GetObj(0)->GetController()->MakeTransition((int)PlayerStateType::GAME_START);
		}

		void UpdateScene(olc::PixelGameEngine* ptrEngine, float deltaTime) override
		{
			sceneObjList.UpdateAll(deltaTime, input.GetHorizontalAxis(ptrEngine));

			sceneObjList.GetObj(1)->Render(ptrEngine, decalLoader.background_decal, RenderOffsetType::NONE);
			sceneObjList.GetObj(0)->Render(ptrEngine, decalLoader.playerbox_green_decal, RenderOffsetType::BOTTOM_CENTER);
			sceneObjList.GetObj(0)->Render(ptrEngine, decalLoader.diamond_red_decal, RenderOffsetType::CENTER_CENTER);

			if (input.QuitGame(ptrEngine))
			{
				bQuit = true;
				std::cout << std::endl;
				std::cout << "---quit triggered---" << std::endl;
			}
		}
	};
}