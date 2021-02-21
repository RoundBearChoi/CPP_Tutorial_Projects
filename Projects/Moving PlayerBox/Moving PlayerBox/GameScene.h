#pragma once
#include "GameObjContainer.h"
#include "Scene.h"
#include "GameDecalLoader.h"
#include "Input.h"
#include "PlayerController.h"
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
		GameObjContainer objContainer;

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
			objContainer.CreateObj((int)GameObjType::player);
			objContainer.CreateObj((int)GameObjType::background);
			objContainer.CreateObj((int)GameObjType::shitgroup);

			objContainer.GetObj((int)GameObjType::player)->SetController<PlayerController>();
			objContainer.GetObj((int)GameObjType::player)->GetController()->MakeTransition((int)PlayerStateType::GAME_START);
		}

		void UpdateScene(olc::PixelGameEngine* ptrEngine, float _deltaTime) override
		{
			GameData gameData;
			gameData.deltaTime = _deltaTime;
			gameData.inputXAxis = input.GetHorizontalAxis(ptrEngine);
			objContainer.UpdateAll(gameData);

			objContainer.GetObj((int)GameObjType::background)->Render(ptrEngine, gameDecalLoader.GetDecal((int)GameSpriteType::background), RenderOffsetType::NONE);
			objContainer.GetObj((int)GameObjType::player)->Render(ptrEngine, gameDecalLoader.GetDecal((int)GameSpriteType::playerbox_green), RenderOffsetType::BOTTOM_CENTER);
			objContainer.GetObj((int)GameObjType::player)->Render(ptrEngine, gameDecalLoader.GetDecal((int)GameSpriteType::diamond_red), RenderOffsetType::CENTER_CENTER);
			objContainer.GetObj((int)GameObjType::shitgroup)->Render(ptrEngine, gameDecalLoader.GetDecal((int)GameSpriteType::redbox_10x10), RenderOffsetType::CENTER_CENTER);

			if (input.ESCPressed(ptrEngine))
			{
				bQuit = true;
				std::cout << std::endl;
				std::cout << "---quit triggered---" << std::endl;
			}
		}
	};
}