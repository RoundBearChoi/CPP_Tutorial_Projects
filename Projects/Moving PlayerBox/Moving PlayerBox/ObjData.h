#pragma once
#include "olcPixelGameEngine.h"
#include "ObjSpecs.h"
#include <vector>

namespace RB
{
	class ObjData
	{
	public:
		olc::vf2d position = olc::vf2d(0.0f, 0.0f);
		std::vector<ObjSpecs> vecChildSpecs;
	};
}