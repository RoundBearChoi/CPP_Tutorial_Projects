#pragma once
#include "olcPixelGameEngine.h"
#include "GameData.h"

namespace RB
{
	class State
	{
	public:
		virtual void UpdateState(olc::vf2d& pos, const GameData& gameData) = 0;
		int* nextStatePtr = nullptr;

		virtual ~State()
		{

		}
	};
}