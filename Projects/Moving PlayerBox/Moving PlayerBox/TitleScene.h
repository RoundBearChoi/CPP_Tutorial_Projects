#pragma once
#include "Scene.h"

namespace RB
{
	class TitleScene : public Scene
	{
	private:
		int frameCount = 0;

	public:
		TitleScene()
		{
			std::cout << "constructing TitleScene" << std::endl;
		}

		~TitleScene()
		{
			std::cout << "destructing TitleScene" << std::endl;
		}

		void InitScene() override
		{

		}

		void UpdateScene(olc::PixelGameEngine* ptrEngine, const GameData& gameData) override
		{
			frameCount++;

			if (frameCount >= 1 * 120)
			{
				nNextSceneQueue = 2;
			}
		}

		void RenderScene(olc::PixelGameEngine* ptrEngine) override
		{

		}
	};
}