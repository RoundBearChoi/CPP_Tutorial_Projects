#pragma once
#define OLC_PGE_APPLICATION 0
#include "olcPixelGameEngine.h"
#include "SpriteAnimation.h"

class Game : public olc::PixelGameEngine
{
private:
	olc::Sprite* spritePtr = nullptr;
	olc::Decal* decalPtr = nullptr;
	SpriteAnimation spriteAnimation;
	olc::vf2d position = { 0.0f, 0.0f };
	float speed = 50.0f;

public:
	~Game()
	{
		delete spritePtr;
		delete decalPtr;
	}

	bool OnUserCreate() override
	{
		spritePtr = new olc::Sprite("ryuback_spritesheet.png");
		decalPtr = new olc::Decal(spritePtr);

		spriteAnimation.SetParams(0.2f, spritePtr->width, spritePtr->height, 6);

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::DARK_BLUE);

		if (GetKey(olc::Key::D).bHeld)
		{
			position.x += (speed * fElapsedTime);
		}

		if (GetKey(olc::Key::A).bHeld)
		{
			position.x -= (speed * fElapsedTime);
		}

		if (GetKey(olc::Key::W).bHeld)
		{
			position.y -= (speed * fElapsedTime);
		}

		if (GetKey(olc::Key::S).bHeld)
		{
			position.y += (speed * fElapsedTime);
		}

		AnimationData animationData = spriteAnimation.GetInfo(fElapsedTime);
		olc::vf2d size = { 3000.0f / 3.0f / 5.0f, 728.0f / 3.0f };
		DrawPartialDecal(position, size, decalPtr, animationData.sourcePos, animationData.sourceSize);

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