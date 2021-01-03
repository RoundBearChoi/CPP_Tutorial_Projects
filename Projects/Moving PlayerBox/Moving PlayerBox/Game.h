#pragma once
#define OLC_PGE_APPLICATION 0
#include "olcPixelGameEngine.h"
#include "GameProcessor.h"

namespace RB
{
	class Game : public olc::PixelGameEngine
	{
	private:
		GameProcessor gameProcessor;

	public:
		bool OnUserCreate() override
		{
			gameProcessor.Init(this);
			return true;
		}

		bool OnUserUpdate(float fElapsedTime) override
		{
			gameProcessor.Update(fElapsedTime);
			return true;
		}

		void Run()
		{
			if (Construct(550, 700, 1, 1))
			{
				Start();
			}
		}
	};
}