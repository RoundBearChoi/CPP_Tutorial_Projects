#pragma once
#include "State.h"

namespace RB
{
	class ShitFall : public State
	{
	public:
		ShitFall()
		{
			std::cout << "constructing State: ShitFall" << std::endl;
		}

		~ShitFall()
		{
			std::cout << std::endl;
			std::cout << "destructing State: ShitFall" << std::endl;
		}

		void UpdateState(ObjData& objData, const GameData& gameData)
		{

		}

		void UpdateState2(GameObj* ptrObj, const GameData& gameData) override
		{

		}
	};
}