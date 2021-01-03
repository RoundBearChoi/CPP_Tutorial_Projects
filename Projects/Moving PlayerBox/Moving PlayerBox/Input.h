#pragma once
#include "olcPixelGameEngine.h"

namespace RB
{
	class Input
	{
	private:
		float xAxis = 0.0f;
		bool bHeldLeft = false;
		bool bHeldRight = false;
	public:
		float GetXAxis()
		{
			return xAxis;
		}

		void GetUserInput(olc::PixelGameEngine* engine)
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
				xAxis = 0.0f;
			}
			else
			{
				if (bHeldLeft)
				{
					xAxis = -0.1f;
				}
				else if (bHeldRight)
				{
					xAxis = 0.1f;
				}
			}
		}
	};
}