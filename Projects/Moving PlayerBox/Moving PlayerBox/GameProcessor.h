#pragma once
#include "DecalLoader.h"
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
		Input input;

		SceneObjList sceneObjList;

	public:
		void Init(olc::PixelGameEngine* olcEngine)
		{
			engine = olcEngine;
			decalLoader.LoadAll();

			sceneObjList.CreateObj("player");
			sceneObjList.CreateObj("background");

			sceneObjList.GetObj(0)->SetController<PlayerController>();
			sceneObjList.GetObj(0)->GetController()->MakeTransition((int)PlayerStateType::GAME_START);
		}

		void Update(float fElapsedTime)
		{
			sceneObjList.UpdateAll(fElapsedTime, input.GetHorizontalAxis(engine));

			sceneObjList.GetObj(1)->Render(engine, decalLoader.background_decal, RenderOffsetType::NONE);
			sceneObjList.GetObj(0)->Render(engine, decalLoader.playerbox_green_decal, RenderOffsetType::BOTTOM_CENTER);
			sceneObjList.GetObj(0)->Render(engine, decalLoader.diamond_red_decal, RenderOffsetType::CENTER_CENTER);
		}
	};
}