#pragma once
#include "olcPixelGameEngine.h"

namespace RB
{
	class Scene
	{
	public:
		virtual void InitScene() = 0;
		virtual void UpdateScene(olc::PixelGameEngine* ptrEngine, float deltaTime) = 0;
	};
}