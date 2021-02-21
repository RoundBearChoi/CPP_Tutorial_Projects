#pragma once
#include "GameData.h"

namespace RB
{
	class PlayerState
	{
	public:
		virtual void UpdateState(olc::vf2d& pos, const GameData& gameData) = 0;
		int* nextStatePtr = nullptr;

		PlayerState()
		{
			std::cout << std::endl;
			std::cout << "constructing PlayerState" << std::endl;
		}

		virtual ~PlayerState()
		{
			std::cout << "destructing PlayerState (virtual)" << std::endl;
		}
	};
}