#pragma once
#include "Scene.h"
#include "GameScene.h"
#include "DevSettings.h"
#include "SceneType.h"

#include "TitleScene.h"
#include "GameScene.h"

namespace RB
{
	class SceneController
	{
	private:
		Scene* currentScene = nullptr;
		DecalLoader titleSceneDecalLoader;
		DecalLoader gameSceneDecalLoader;

	public:
		SceneController()
		{
			IF_COUT{ std::cout << "constructing SceneController" << std::endl; }
		}

		~SceneController()
		{
			IF_COUT{ std::cout << "destructing SceneController" << std::endl; }

			delete currentScene;
		}

		void CreateScene(SceneType _sceneType)
		{
			delete currentScene;

			if (_sceneType == SceneType::TITLE_SCENE)
			{
				currentScene = new TitleScene();
			}
			else if (_sceneType == SceneType::GAME_SCENE)
			{
				currentScene = new GameScene();
			}

			currentScene->InitScene();
		}

		void UpdateCurrentScene(olc::PixelGameEngine* ptrEngine, GameData& gameData, float deltaTime)
		{
			currentScene->UpdateScene(ptrEngine, gameData);
		}

		void RenderCurrentScene(olc::PixelGameEngine* ptrEngine, float deltaTime)
		{
			currentScene->RenderObjs(ptrEngine);
			currentScene->RenderStates(ptrEngine);
		}
	};
}