#pragma once
#include "DecalLoader.h"
#include "Input.h"
#include "PlayerController.h"
#include "SceneObjList.h"

#include "Scene.h"

namespace RB
{
	class GameProcessor
	{
	private:
		Scene scene;

	public:
		void Init()
		{
			scene.InitScene();
		}

		void Update(olc::PixelGameEngine* ptrEngine, float fElapsedTime)
		{
			scene.UpdateScene(ptrEngine, fElapsedTime);
		}
	};
}