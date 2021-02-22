#pragma once
#include "State.h"
#include "GameObjType.h"
#include "ControllerType.h"

namespace RB
{
	class ShitGenerator : public State
	{
	private:
		bool testing = true;

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
			if (testing)
			{
				objData.QueueChild(GameObjType::individual_shit, ControllerType::FALLING_SHIT_CONTROLLER);
				testing = false;
			}
		}

		void UpdateState2(GameObj* ptrObj, const GameData& gameData) override
		{

		}
	};
}