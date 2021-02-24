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
		bool bStartSlowMo = false;

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

			if (bStartSlowMo)
			{
				fTargetFrameTime = 1.0f / 5.0f;
			}

			if (fAccumulatedTime >= fTargetFrameTime)
			{
				GameData gameData;
				gameData.inputXAxis = input.GetHorizontalAxis();
				gameData.startGame = input.StartGame();

				fAccumulatedTime -= fTargetFrameTime;
				fElapsedTime = fTargetFrameTime;

				sceneController.UpdateCurrentScene(this, gameData, fElapsedTime);
				sceneController.RenderCurrentScene(this, fElapsedTime);

				//scene transition
				if (gameData.nextSceneIndex != 0)
				{
					if (gameData.nextSceneIndex == 2)
					{
						sceneController.CreateScene<GameScene>();
					}
				}

				//only clear after update
				input.ClearKeyPress();

				if (gameData.startSlowMo)
				{
					bStartSlowMo = true;
				}
			}
			else
			{
				sceneController.RenderCurrentScene(this, fElapsedTime);
			}

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