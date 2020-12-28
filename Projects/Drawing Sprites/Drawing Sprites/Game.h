#pragma once
#define OLC_PGE_APPLICATION 0
#include "olcPixelGameEngine.h"
//#include <iostream>

class Game : public olc::PixelGameEngine
{
private:
	olc::Sprite* spritePtr = nullptr;
	olc::Decal* decalPtr = nullptr;
	olc::vf2d decalPos;
	float speed = 50.0f;

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
		decalPos.x = 0.0f;
		decalPos.y = 0.0f;

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::DARK_BLUE);

		if (GetKey(olc::Key::A).bHeld)
		{
			decalPos.x -= (speed * fElapsedTime);
		}
		if (GetKey(olc::Key::D).bHeld)
		{
			decalPos.x += (speed * fElapsedTime);
		}
		if (GetKey(olc::Key::W).bHeld)
		{
			decalPos.y -= (speed * fElapsedTime);
		}
		if (GetKey(olc::Key::S).bHeld)
		{
			decalPos.y += (speed * fElapsedTime);
		}

		//decalPos = GetMousePos();

		//DrawSprite(position, spritePtr);
		DrawDecal(decalPos, decalPtr);

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