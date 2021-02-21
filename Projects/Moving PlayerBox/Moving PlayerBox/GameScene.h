#pragma once
#include "Scene.h"
#include "GameDecalLoader.h"
#include "Input.h"
#include "GameObjList.h"
#include "GameData.h"
#include "SpriteType.h"

namespace RB
{
	enum class GameObjType
	{
		player,
		background,
		shitgroup,
	};

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
			gameObjList.CreateObj((int)GameObjType::player);
			gameObjList.CreateObj((int)GameObjType::background);
			gameObjList.CreateObj((int)GameObjType::shitgroup);

			gameObjList.GetObj((int)GameObjType::player)->SetController((int)ControllerType::PLAYER);
		}

		void UpdateScene(olc::PixelGameEngine* ptrEngine, float _deltaTime) override
		{
			GameData gameData;
			gameData.deltaTime = _deltaTime;
			gameData.inputXAxis = input.GetHorizontalAxis(ptrEngine);
			gameObjList.UpdateAll(gameData);

			gameObjList.GetObj((int)GameObjType::background)->Render(ptrEngine, gameDecalLoader.GetDecal((int)GameSpriteType::background), RenderOffsetType::NONE);
			gameObjList.GetObj((int)GameObjType::player)->Render(ptrEngine, gameDecalLoader.GetDecal((int)GameSpriteType::playerbox_green), RenderOffsetType::BOTTOM_CENTER);
			gameObjList.GetObj((int)GameObjType::player)->Render(ptrEngine, gameDecalLoader.GetDecal((int)GameSpriteType::diamond_red), RenderOffsetType::CENTER_CENTER);
			gameObjList.GetObj((int)GameObjType::shitgroup)->Render(ptrEngine, gameDecalLoader.GetDecal((int)GameSpriteType::redbox_10x10), RenderOffsetType::CENTER_CENTER);

			if (input.ESCPressed(ptrEngine))
			{
				bQuit = true;
				std::cout << std::endl;
				std::cout << "---quit triggered---" << std::endl;
			}
		}
	};
}