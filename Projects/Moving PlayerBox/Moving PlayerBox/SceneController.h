#pragma once
#include "Scene.h"

namespace RB
{
	class SceneController
	{
	private:
		Scene* currentScene = nullptr;

	public:
		~SceneController()
		{
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
		}
	};
}