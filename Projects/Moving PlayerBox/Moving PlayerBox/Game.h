#pragma once
#define OLC_PGE_APPLICATION 0
#include "olcPixelGameEngine.h"
#include "SceneController.h"
#include "GameScene.h"
#include "TitleScene.h"

namespace RB
{
	class Game : public olc::PixelGameEngine
	{
	private:
		SceneController sceneController;

	public:
		bool OnUserCreate() override
		{
			sceneController.CreateScene<GameScene>();
			return true;
		}

		bool OnUserUpdate(float fElapsedTime) override
		{
			if (!sceneController.QuitGame())
			{
				sceneController.UpdateCurrentScene(this, fElapsedTime);
				return true;
			}
			else
			{
				return false;
			}
		}

		void Run()
		{
			if (Construct(600, 700, 1, 1))
			{
				Start();
			}
		}
	};
}