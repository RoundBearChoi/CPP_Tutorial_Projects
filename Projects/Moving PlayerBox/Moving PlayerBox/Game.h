#pragma once
#define OLC_PGE_APPLICATION 0
#include "olcPixelGameEngine.h"
#include "SceneController.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "GameData.h"
#include "Input.h"

namespace RB
{
	class Game : public olc::PixelGameEngine
	{
	private:
		SceneController sceneController;
		Input input;
		float fTargetFrameTime = 1.0f / 120.0f; // target fixed timestep
		float fAccumulatedTime = 0.0f;

	public:
		bool OnUserCreate() override
		{
			sAppName = "ShitFall";
			sceneController.CreateScene<TitleScene>();
			return true;
		}

		bool OnUserUpdate(float fElapsedTime) override
		{
			if (input.ESCPressed())
			{
				return false;
			}

			input.UpdateInput(this);

			fAccumulatedTime += fElapsedTime;

			if (fAccumulatedTime >= fTargetFrameTime)
			{
				GameData gameData;
				gameData.inputXAxis = input.GetHorizontalAxis();
				gameData.startGame = input.StartGame();

				fAccumulatedTime -= fTargetFrameTime;
				fElapsedTime = fTargetFrameTime;

				sceneController.UpdateCurrentScene(this, gameData, fElapsedTime);
				sceneController.RenderCurrentScene(this, fElapsedTime);

				//only clear after update
				input.ClearQueue();
			}
			else
			{
				sceneController.RenderCurrentScene(this, fElapsedTime);
			}

			input.Queue();
			return true;
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