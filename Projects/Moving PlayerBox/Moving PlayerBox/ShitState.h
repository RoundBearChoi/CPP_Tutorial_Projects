#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "GameData.h"

namespace RB
{
	class ShitState
	{
	public:
		virtual void UpdateState(olc::vf2d& pos, const GameData& gameData) = 0;
		int* nextStatePtr = nullptr;

		ShitState()
		{
			std::cout << std::endl;
			std::cout << "constructing ShitState" << std::endl;
		}

		virtual ~ShitState()
		{
			std::cout << "destructing ShitState" << std::endl;
		}
	};
}