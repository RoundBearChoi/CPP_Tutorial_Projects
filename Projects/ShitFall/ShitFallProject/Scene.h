#pragma once
#include "olcPixelGameEngine.h"
#include "GameData.h"
#include "GameObjList.h"
#include "DecalLoader.h"
#include "DevSettings.h"

namespace RB
{
	class Scene
	{
	protected:
		GameObjList objList;

	public:
		virtual void InitScene() = 0;
		virtual void UpdateScene(olc::PixelGameEngine* ptrEngine, GameData& gameData) = 0;
		virtual void RenderObjs(olc::PixelGameEngine* ptrEngine) = 0;
		virtual void RenderStates(olc::PixelGameEngine* ptrEngine) = 0;

		Scene()
		{
			IF_COUT
			{ 
				std::cout << std::endl;
				std::cout << "constructing Scene (virtual)" << std::endl;
			}
		}

		virtual ~Scene()
		{

		}
	};
}