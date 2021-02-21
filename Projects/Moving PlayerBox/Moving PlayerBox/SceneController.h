#pragma once
#include "Scene.h"
#include "GameScene.h"
#include <iostream>

namespace RB
{
	class SceneController
	{
	private:
		Scene* currentScene = nullptr;

	public:
		SceneController()
		{
			std::cout << "constructing SceneController" << std::endl;
		}

		~SceneController()
		{
			std::cout << "destructing SceneController" << std::endl;
			delete currentScene;
		}

		template<class T>
		void CreateScene()
		{
			delete currentScene;

			if (std::is_base_of<Scene, T>::value)
			{
				currentScene = new T();
				currentScene->InitScene();
			}
		}

		void UpdateCurrentScene(olc::PixelGameEngine* ptrEngine, float deltaTime)
		{
			currentScene->UpdateScene(ptrEngine, deltaTime);

			int nextScene = currentScene->GetNextScene();

			if (nextScene != 0)
			{
				if (nextScene == 2)
				{
					CreateScene<GameScene>();
				}
			}
		}

		bool QuitGame()
		{
			return currentScene->QuitGame();
		}
	};
}