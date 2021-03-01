#pragma once
#define OLC_PGE_APPLICATION 0
#include "olcPixelGameEngine.h"
#include "SceneController.h"
#include "SceneType.h"
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
			sceneController.CreateScene(SceneType::TITLE_SCENE);
			return true;
		}

		bool OnUserUpdate(float fElapsedTime) override
		{
			if (input.GetESCPress(this))
			{
				return false;
			}

			input.UpdateInput(this);

			fAccumulatedTime += fElapsedTime;

			//fixed timestep
			if (fAccumulatedTime >= fTargetFrameTime)
			{
				GameData gameData;
				gameData.inputXAxis = input.GetHorizontalAxis();
				gameData.startGame = input.StartGame();
				gameData.yPressed = input.GetYPress(this);
				gameData.nPressed = input.GetNPress(this);

				fAccumulatedTime -= fTargetFrameTime;
				fElapsedTime = fTargetFrameTime;

				sceneController.UpdateCurrentScene(this, gameData, fElapsedTime);
				sceneController.RenderCurrentScene(true, this, fElapsedTime);

				//scene transition
				if (gameData.nextSceneType != SceneType::NONE)
				{
					sceneController.CreateScene(gameData.nextSceneType);
				}

				//only clear after update
				input.ClearKeyPress();

				if (gameData.quitGame)
				{
					return false;
				}
			}
			else
			{
				sceneController.RenderCurrentScene(false, this, fElapsedTime);
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