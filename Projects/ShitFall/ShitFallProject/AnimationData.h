#pragma once
#include "olcPixelGameEngine.h"

namespace RB
{
	class AnimationData
	{
	public:
		int decalIndex = 0;
		olc::vf2d sourcePos = { 0.0f, 0.0f };
		olc::vf2d sourceSize = { 0.0f, 0.0f };
	};
}