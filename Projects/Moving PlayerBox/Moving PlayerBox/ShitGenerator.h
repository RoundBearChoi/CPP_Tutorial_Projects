#pragma once
#include "State.h"
#include "GameObjType.h"
#include "ControllerType.h"

namespace RB
{
	class ShitGenerator : public State
	{
	private:
		int frameCount = 0;

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
			frameCount++;

			objData.position = { 0.0f, 350.0f };

			if (frameCount >= 120)
			{
				objData.QueueChildCreation(GameObjType::individual_shit, ControllerType::SHIT_CONTROLLER_FALL);
				frameCount = 0;
			}
		}
	};
}