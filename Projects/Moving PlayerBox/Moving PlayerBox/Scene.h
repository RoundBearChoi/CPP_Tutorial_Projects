#pragma once
#include "olcPixelGameEngine.h"
#include "GameData.h"

namespace RB
{
	class Scene
	{
	protected:
		int nextSceneIndex = 0;

	public:
		virtual void InitScene() = 0;
		virtual void UpdateScene(olc::PixelGameEngine* ptrEngine, const GameData& gameData) = 0;
		virtual void RenderScene(olc::PixelGameEngine* ptrEngine) = 0;

		Scene()
		{
			std::cout << std::endl;
			std::cout << "constructing Scene (virtual)" << std::endl;
		}

		virtual ~Scene()
		{
			std::cout << "destructing Scene (virtual)" << std::endl;
		}

		int GetNextScene()
		{
			return nextSceneIndex;
		}

		void ClearQueue()
		{
			nextSceneIndex = 0;
		}
	};
}