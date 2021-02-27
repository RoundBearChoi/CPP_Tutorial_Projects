#pragma once
#include "State.h"

namespace RB
{
	class ShitSplash : public State
	{
	public:
		ShitSplash()
		{
			IF_COUT{ std::cout << "constructing State: ShitSplash" << std::endl; }
		}

		~ShitSplash()
		{
			IF_COUT
			{
				std::cout << std::endl;
				std::cout << "destructing State: ShitSplash" << std::endl;
			}
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			deleteObj = true;
		}
	};
}