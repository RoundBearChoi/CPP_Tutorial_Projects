#pragma once
#include "olcPixelGameEngine.h"

namespace RB
{
	class Input
	{
	private:
		bool bHeldLeft = false;
		bool bHeldRight = false;

	public:
		float GetHorizontalAxis(olc::PixelGameEngine* engine)
		{
			if (engine->GetKey(olc::Key::A).bHeld)
			{
				bHeldLeft = true;
			}
			else
			{
				bHeldLeft = false;
			}

			if (engine->GetKey(olc::Key::D).bHeld)
			{
				bHeldRight = true;
			}
			else
			{
				bHeldRight = false;
			}

			// both pressed OR nothing pressed
			if (bHeldLeft && bHeldRight || !bHeldLeft && !bHeldRight)
			{
				return 0.0f;
			}
			else
			{
				if (bHeldLeft)
				{
					return -0.1f;
				}
				else if (bHeldRight)
				{
					return 0.1f;
				}
			}

			return 0.0f;
		}

		bool QuitGame(olc::PixelGameEngine* engine)
		{
			if (engine->GetKey(olc::Key::ESCAPE).bHeld)
			{
				return true;
			}

			return false;
		}
	};
}