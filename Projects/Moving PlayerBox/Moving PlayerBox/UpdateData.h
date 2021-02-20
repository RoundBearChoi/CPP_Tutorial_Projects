#pragma once
#include "olcPixelGameEngine.h"

namespace RB
{
	class UpdateData
	{
	public:
		float inputXAxis = 0.0f;
		float elapsedTime = 0.0f;
		olc::vf2d pos = olc::vf2d(0.0f, 0.0f);
	};
}