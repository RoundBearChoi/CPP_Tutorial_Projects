#pragma once
#include "ShitState.h"

namespace RB
{
	class ShitFall : public ShitState
	{
	public:
		ShitFall()
		{
			std::cout << "constructing ShitFall (ShitState)" << std::endl;
		}

		~ShitFall() override
		{
			std::cout << "destructing ShitFall (ShitState)" << std::endl;
		}

		virtual void UpdateState(olc::vf2d& pos, const GameData& gameData)
		{

		}
	};
}