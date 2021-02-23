#pragma once
#include "State.h"

namespace RB
{
	class ShitPosition : public State
	{
		ShitPosition()
		{
			std::cout << std::endl;
			std::cout << "constructing State: ShitPosition" << std::endl;
		}

		~ShitPosition()
		{
			std::cout << std::endl;
			std::cout << "destructing State: ShitPosition" << std::endl;
		}

		void UpdateState(ObjData& objData, const GameData& gameData)
		{

		}
	};
}