#pragma once
#include "olcPixelGameEngine.h"

namespace RB
{
	class AnimationData
	{
	public:
		int decalTypeIndex = 0;
		int currentTile = 0;
		bool reverseDecal = false;
		bool playOnce = false;
		olc::vf2d sourcePos = { 0.0f, 0.0f };
		olc::vf2d sourceSize = { 0.0f, 0.0f };

		//skipping transitions
		int transitionDelay = 0;
		int delayCount = 0;
	};
}