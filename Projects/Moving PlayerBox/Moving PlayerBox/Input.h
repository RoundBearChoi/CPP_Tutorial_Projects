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
		int GetHorizontalAxis(olc::PixelGameEngine* engine)
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
				return 0;
			}
			else
			{
				if (bHeldLeft)
				{
					return -1;
				}
				else if (bHeldRight)
				{
					return 1;
				}
			}

			return 0;
		}

		bool ESCPressed(olc::PixelGameEngine* engine)
		{
			if (engine->GetKey(olc::Key::ESCAPE).bHeld)
			{
				return true;
			}

			return false;
		}
	};
}