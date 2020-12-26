#pragma once
#define OLC_PGE_APPLICATION 0
#include "olcPixelGameEngine.h"
//#include <iostream>

class Game : public olc::PixelGameEngine
{
private:
	olc::Sprite* spritePtr = nullptr;
	olc::Decal* decalPtr = nullptr;

public:
	~Game()
	{
		delete spritePtr;
		delete decalPtr;
	}

	bool OnUserCreate() override
	{
		//std::filesystem::path startingPath = std::filesystem::current_path();
		spritePtr = new olc::Sprite("synthetikcharacter.png");
		decalPtr = new olc::Decal(spritePtr);

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::DARK_BLUE);

		olc::vf2d position(10, 20);
		//DrawSprite(position, spritePtr);
		DrawDecal(position, decalPtr);

		olc::vf2d stringposition(0, 0);
		DrawString(stringposition, "this is a string", olc::DARK_RED);

		return true;
	}

	void run()
	{
		if (Construct(600, 300, 2, 2))
		{
			Start();
		}
	}
};