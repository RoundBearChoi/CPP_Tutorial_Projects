#pragma once
#include "olcPixelGameEngine.h"

namespace RB
{
	class Scene
	{
	protected:
		bool bQuit = false;

	public:
		virtual void InitScene() = 0;
		virtual void UpdateScene(olc::PixelGameEngine* ptrEngine, float deltaTime) = 0;

		virtual ~Scene()
		{
			std::cout << "destructing Scene (virtual)" << std::endl;
		}

		bool QuitGame()
		{
			return bQuit;
		}
	};
}