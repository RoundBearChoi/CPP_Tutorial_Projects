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
				objData.QueueChildCreation(GameObjType::individual_shit, ControllerType::SHIT_CONTROLLER_FALL);
				testing = false;
			}
		}
	};
}