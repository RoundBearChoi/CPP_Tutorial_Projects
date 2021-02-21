#pragma once
#include "olcPixelGameEngine.h"
#include "DecalLoader.h"

namespace RB
{
	class GameDecalLoader : public DecalLoader
	{
	public:
		olc::Sprite* diamond_red_sprite = nullptr;
		olc::Sprite* playerbox_green_sprite = nullptr;
		olc::Sprite* background_sprite = nullptr;

		olc::Decal* diamond_red_decal = nullptr;
		olc::Decal* playerbox_green_decal = nullptr;
		olc::Decal* background_decal = nullptr;

		GameDecalLoader()
		{
			std::cout << "constructing GameDecalLoader" << std::endl;

			LoadSprites();
			LoadDecals();
		}

		~GameDecalLoader() override
		{
			std::cout << "destructing GameDecalLoader" << std::endl;

			delete diamond_red_sprite;
			delete playerbox_green_sprite;
			delete background_sprite;

			delete diamond_red_decal;
			delete playerbox_green_decal;
			delete background_decal;
		}

		void LoadSprites()
		{
			diamond_red_sprite = new olc::Sprite("PNG files/diamond_red.png");
			playerbox_green_sprite = new olc::Sprite("PNG files/playerbox_green.png");
			background_sprite = new olc::Sprite("PNG files/background.png");
		}

		void LoadDecals()
		{
			diamond_red_decal = new olc::Decal(diamond_red_sprite);
			playerbox_green_decal = new olc::Decal(playerbox_green_sprite);
			background_decal = new olc::Decal(background_sprite);
		}
	};
}