#pragma once
#define OLC_PGE_APPLICATION 0
#include "olcPixelGameEngine.h"

namespace RB
{
	class Game : public olc::PixelGameEngine
	{
	public:
		bool OnUserCreate() override
		{
			return true;
		}

		bool OnUserUpdate(float fElapsedTime) override
		{
			return true;
		}

		void Run()
		{
			if (Construct(500, 600, 1, 1))
			{
				Start();
			}
		}
	};
}