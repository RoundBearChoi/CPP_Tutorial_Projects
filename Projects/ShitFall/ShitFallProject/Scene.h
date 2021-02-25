#pragma once
#include "olcPixelGameEngine.h"
#include "GameData.h"
#include "GameObjTree.h"

namespace RB
{
	class Scene
	{
	protected:
		GameObjTree objTree;

	public:
		virtual void InitScene() = 0;
		virtual void UpdateScene(olc::PixelGameEngine* ptrEngine, GameData& gameData) = 0;
		virtual void RenderObjs(olc::PixelGameEngine* ptrEngine) = 0;
		virtual void RenderStates(olc::PixelGameEngine* ptrEngine) = 0;

		Scene()
		{
			std::cout << std::endl;
			std::cout << "constructing Scene (virtual)" << std::endl;
		}

		virtual ~Scene()
		{
			std::cout << "destructing Scene (virtual)" << std::endl;
		}
	};
}