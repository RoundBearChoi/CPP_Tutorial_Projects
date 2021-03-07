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
		spritePtr = new olc::Sprite("hadouken_sprite_sheet.png");
		decalPtr = new olc::Decal(spritePtr);

		spriteAnimation.SetParams(0.125f, spritePtr->width, spritePtr->height, 6, 5, 26);

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

		olc::vf2d size = { 480.0f, 228.0f };
		DrawPartialDecal(position, size, decalPtr, animationData.sourcePos, animationData.sourceSize);
		
		// warping
		//std::array<olc::vf2d, 4> points;
		//points[0] = { 0.0f, 0.0f };
		//points[1] = { 0.0f, 228.0f };
		//points[2] = { 480.0f, 228.0f };
		//points[3] = { 480.0f, 0.0f };
		//DrawPartialWarpedDecal(decalPtr, points, animationData.sourcePos, animationData.sourceSize);

		//std::array<olc::vf2d, 4> points;
		//points[0] = { 480.0f, 0.0f };
		//points[1] = { 480.0f, 228.0f };
		//points[2] = { 0.0f, 228.0f };
		//points[3] = { 0.0f, 0.0f };
		//DrawPartialWarpedDecal(decalPtr, points, animationData.sourcePos, animationData.sourceSize);

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