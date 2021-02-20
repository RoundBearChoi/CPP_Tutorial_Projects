#pragma once
#include "DecalLoader.h"
#include "SceneObj.h"
#include "Input.h"
#include "PlayerController.h"

#include "SceneObjList.h"
#include "SceneDataset.h"
#include "SceneUpdater.h"

namespace RB
{
	class GameProcessor
	{
	private:
		olc::PixelGameEngine* engine = nullptr;
		DecalLoader decalLoader;
		SceneObj player;
		SceneObj background;
		Input input;

		SceneObjList sceneObjList;
		SceneDataset sceneDataset;

		SceneUpdater sceneUpdater;

	public:
		void Init(olc::PixelGameEngine* olcEngine)
		{
			engine = olcEngine;
			decalLoader.LoadAll();

			player.SetController<PlayerController>();
			player.GetController()->MakeTransition((int)PlayerStateType::GAME_START);

			sceneObjList.CreateObj("player");
			sceneObjList.CreateObj("background");

			sceneObjList.GetObj(0)->SetController<PlayerController>();
			sceneObjList.GetObj(0)->GetController()->MakeTransition((int)PlayerStateType::GAME_START);

			sceneDataset.ptrObjList = &sceneObjList;
			sceneDataset.ptrInput = &input;

			//temp
			player.SetPos(300.0f, 650.0f);
			player.SetSpeed(200.0f, 0.0f);
		}

		void Update(float fElapsedTime)
		{
			sceneUpdater.Update(sceneDataset);

			InputData inputData = input.GetUserInput(engine);
			player.GetController()->Update(inputData);
			player.GetController()->CheckNextTransition();
			//sceneObjList.UpdateAll();
			player.UpdatePos(fElapsedTime, inputData.xAxis);
			
			background.Render(engine, decalLoader.background_decal, RenderOffsetType::NONE);
			player.Render(engine, decalLoader.playerbox_green_decal, RenderOffsetType::BOTTOM_CENTER);
			player.Render(engine, decalLoader.diamond_red_decal, RenderOffsetType::CENTER_CENTER);
		}
	};
}