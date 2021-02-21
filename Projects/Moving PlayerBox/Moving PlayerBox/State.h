#pragma once
#include "olcPixelGameEngine.h"
#include "GameData.h"

namespace RB
{
	class State
	{
	protected:
		int nextStateIndex = 0;

	public:
		virtual void UpdateState(olc::vf2d& pos, const GameData& gameData) = 0;

		virtual ~State()
		{

		}

		int GetNextStateIndex()
		{
			return nextStateIndex;
		}
	};
}