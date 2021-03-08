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
		DecalLoader titleSceneDecalLoader{ SceneType::TITLE_SCENE };
		DecalLoader gameSceneDecalLoader{ SceneType::GAME_SCENE };

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
				if (titleSceneDecalLoader.GetSpriteCount() == 0)
				{
					titleSceneDecalLoader.LoadSprites<TitleDecalPath>();
					titleSceneDecalLoader.LoadDecals();
				}

				currentScene = new TitleScene(&titleSceneDecalLoader);
			}
			else if (_sceneType == SceneType::GAME_SCENE)
			{
				if (gameSceneDecalLoader.GetSpriteCount() == 0)
				{
					gameSceneDecalLoader.LoadSprites<GameDecalPath>();
					gameSceneDecalLoader.LoadDecals();
				}

				currentScene = new GameScene(&gameSceneDecalLoader);
			}

			currentScene->InitScene();
		}

		void UpdateCurrentScene(olc::PixelGameEngine* ptrEngine, GameData& gameData)
		{
			currentScene->UpdateScene(ptrEngine, gameData);
		}

		void RenderCurrentScene(bool update, olc::PixelGameEngine* ptrEngine)
		{
			currentScene->RenderObjs(ptrEngine);
			currentScene->RenderStates(update, ptrEngine);
		}
	};
}