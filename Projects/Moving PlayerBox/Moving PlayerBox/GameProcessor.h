#pragma once
#include "DecalLoader.h"
#include "SceneObj.h"
#include "Input.h"
#include "PlayerController.h"

#include "SceneObjList.h"

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

	public:
		void Init(olc::PixelGameEngine* olcEngine)
		{
			engine = olcEngine;
			decalLoader.LoadAll();

			player.SetController<PlayerController>();
			player.SetUpdateData();
			player.GetController()->MakeTransition((int)PlayerStateType::GAME_START);
			
			sceneObjList.CreateObj("player");
			sceneObjList.CreateObj("background");

			sceneObjList.GetObj(0)->SetController<PlayerController>();
			sceneObjList.GetObj(0)->GetController()->MakeTransition((int)PlayerStateType::GAME_START);

			//temp
			player.SetPos(300.0f, 650.0f);
			player.SetSpeed(200.0f, 0.0f);
		}

		void Update(float fElapsedTime)
		{
			sceneObjList.UpdateAll(fElapsedTime, input.GetHorizontalAxis(engine));

			player.UpdatePos(fElapsedTime, input.GetHorizontalAxis(engine)); //temp
			
			background.Render(engine, decalLoader.background_decal, RenderOffsetType::NONE);
			player.Render(engine, decalLoader.playerbox_green_decal, RenderOffsetType::BOTTOM_CENTER);
			player.Render(engine, decalLoader.diamond_red_decal, RenderOffsetType::CENTER_CENTER);
		}
	};
}