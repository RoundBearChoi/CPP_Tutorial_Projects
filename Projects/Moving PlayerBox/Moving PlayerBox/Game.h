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
		float fTargetFrameTime = 1.0f / 120.0f; // Virtual FPS of 120fps
		float fAccumulatedTime = 0.0f;

	public:
		bool OnUserCreate() override
		{
			sceneController.CreateScene<TitleScene>();
			return true;
		}

		bool OnUserUpdate(float fElapsedTime) override
		{
			if (!sceneController.QuitGame())
			{
				fAccumulatedTime += fElapsedTime;
				if (fAccumulatedTime >= fTargetFrameTime)
				{
					fAccumulatedTime -= fTargetFrameTime;
					fElapsedTime = fTargetFrameTime;

					sceneController.UpdateCurrentScene(this, fElapsedTime);
					sceneController.RenderCurrentScene(this, fElapsedTime);
					return true;
				}
				else
				{
					sceneController.RenderCurrentScene(this, fElapsedTime);
					return true;
				}
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