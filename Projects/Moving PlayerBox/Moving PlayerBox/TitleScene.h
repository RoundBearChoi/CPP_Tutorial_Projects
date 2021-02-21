#pragma once
#include "Scene.h"

namespace RB
{
	class TitleScene : public Scene
	{
	private:
		float fTesting = 0.0f;

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

		void UpdateScene(olc::PixelGameEngine* ptrEngine, float _deltaTime) override
		{
			fTesting += _deltaTime;

			if (fTesting >= 2.0f)
			{
				nNextSceneQueue = 2;
			}
		}
	};
}