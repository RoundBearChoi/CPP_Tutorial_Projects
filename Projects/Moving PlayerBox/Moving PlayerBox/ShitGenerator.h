#pragma once
#include "State.h"

namespace RB
{
	class ShitGenerator : public State
	{
	public:
		ShitGenerator()
		{
			std::cout << std::endl;
			std::cout << "constructing State: ShitGenerator" << std::endl;
		}

		~ShitGenerator()
		{
			std::cout << std::endl;
			std::cout << "destructing State: ShitGenerator" << std::endl;
		}

		void UpdateState(ObjData& objData, const GameData& gameData)
		{

		}
	};
}