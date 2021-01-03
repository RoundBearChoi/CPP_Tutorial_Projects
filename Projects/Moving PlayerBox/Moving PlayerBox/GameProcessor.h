#pragma once
#include "DecalLoader.h"
#include "Obj.h"
#include "Input.h"

namespace RB
{
	class GameProcessor
	{
	private:
		olc::PixelGameEngine* engine = nullptr;
		DecalLoader decalLoader;
		Obj player;
		Obj background;
		Input input;

	public:
		void Init(olc::PixelGameEngine* olcEngine)
		{
			engine = olcEngine;
			decalLoader.LoadAll();
			player.SetPos(275.0f, 650.0f);
			player.SetSpeed(200.0f, 0.0f);
		}

		void Update(float fElapsedTime)
		{
			input.GetUserInput(engine);
			player.UpdatePos(fElapsedTime, input.GetXAxis());
			
			background.Render(engine, decalLoader.background_decal, RenderOffsetType::NONE);
			player.Render(engine, decalLoader.playerbox_green_decal, RenderOffsetType::BOTTOM_CENTER);
			player.Render(engine, decalLoader.diamond_red_decal, RenderOffsetType::CENTER_CENTER);
		}
	};
}