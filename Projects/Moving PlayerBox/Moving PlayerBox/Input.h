#pragma once
#include "olcPixelGameEngine.h"
#include "InputData.h"

namespace RB
{
	class Input
	{
	private:
		bool bHeldLeft = false;
		bool bHeldRight = false;

	public:
		InputData GetUserInput(olc::PixelGameEngine* engine)
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

			InputData data;

			// both pressed OR nothing pressed
			if (bHeldLeft && bHeldRight || !bHeldLeft && !bHeldRight)
			{
				data.xAxis = 0.0f;
			}
			else
			{
				if (bHeldLeft)
				{
					data.xAxis = -0.1f;
				}
				else if (bHeldRight)
				{
					data.xAxis = 0.1f;
				}
			}

			return data;
		}
	};
}