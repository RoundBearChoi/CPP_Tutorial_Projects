#pragma once
#include "State.h"

namespace RB
{
	class ShitSplash : public State
	{
	public:
		ShitSplash()
		{
			std::cout << "constructing State: ShitSplash" << std::endl;
		}

		~ShitSplash()
		{
			std::cout << std::endl;
			std::cout << "destructing State: ShitSplash" << std::endl;
		}

		void UpdateState(ObjData& objData, const GameData& gameData)
		{
			deleteObj = true;
		}
	};
}