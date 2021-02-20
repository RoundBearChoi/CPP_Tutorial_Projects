#pragma once
#include "Scene.h"
#include "DecalLoader.h"
#include "Input.h"
#include "GameObjList.h"
#include "PlayerController.h"
#include "GameData.h"

namespace RB
{
	class GameScene : public Scene
	{
	private:
		DecalLoader decalLoader;
		Input input;
		GameObjList gameObjList;

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

			gameObjList.CreateObj("player");
			gameObjList.CreateObj("background");

			gameObjList.GetObj(0)->SetController<PlayerController>();
			gameObjList.GetObj(0)->GetController()->MakeTransition((int)PlayerStateType::GAME_START);
		}

		void UpdateScene(olc::PixelGameEngine* ptrEngine, float _deltaTime) override
		{
			GameData gameData;
			gameData.deltaTime = _deltaTime;
			gameData.inputXAxis = input.GetHorizontalAxis(ptrEngine);
			gameObjList.UpdateAll(gameData);

			gameObjList.GetObj(1)->Render(ptrEngine, decalLoader.background_decal, RenderOffsetType::NONE);
			gameObjList.GetObj(0)->Render(ptrEngine, decalLoader.playerbox_green_decal, RenderOffsetType::BOTTOM_CENTER);
			gameObjList.GetObj(0)->Render(ptrEngine, decalLoader.diamond_red_decal, RenderOffsetType::CENTER_CENTER);

			if (input.ESCPressed(ptrEngine))
			{
				bQuit = true;
				std::cout << std::endl;
				std::cout << "---quit triggered---" << std::endl;
			}
		}
	};
}