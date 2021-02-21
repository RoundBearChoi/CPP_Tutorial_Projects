#pragma once
#include "Scene.h"
#include "GameDecalLoader.h"
#include "Input.h"
#include "GameObjList.h"
#include "PlayerController.h"
#include "GameData.h"
#include "SpriteType.h"

namespace RB
{
	class GameScene : public Scene
	{
	private:
		GameDecalLoader gameDecalLoader;
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

			gameObjList.GetObj(1)->Render(ptrEngine, gameDecalLoader.GetDecal((int)GameSpriteType::background), RenderOffsetType::NONE);
			gameObjList.GetObj(0)->Render(ptrEngine, gameDecalLoader.GetDecal((int)GameSpriteType::playerbox_green), RenderOffsetType::BOTTOM_CENTER);
			gameObjList.GetObj(0)->Render(ptrEngine, gameDecalLoader.GetDecal((int)GameSpriteType::diamond_red), RenderOffsetType::CENTER_CENTER);

			if (input.ESCPressed(ptrEngine))
			{
				bQuit = true;
				std::cout << std::endl;
				std::cout << "---quit triggered---" << std::endl;
			}
		}
	};
}