#pragma once
#include "State.h"

namespace RB
{
	class ShitFall : public State
	{
	public:
		ShitFall()
		{
			std::cout << std::endl;
			std::cout << "constructing State: ShitFall" << std::endl;
		}

		~ShitFall()
		{
			std::cout << std::endl;
			std::cout << "destructing State: ShitFall" << std::endl;
		}

		void UpdateState(olc::vf2d& pos, const GameData& gameData)
		{

		}
	};
}