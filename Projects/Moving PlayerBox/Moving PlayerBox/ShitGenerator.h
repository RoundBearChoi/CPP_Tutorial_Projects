#pragma once
#include "State.h"
#include "GameObjType.h"
#include "ControllerType.h"

namespace RB
{
	class ShitGenerator : public State
	{
	private:
		int creationCounter = 0;
		int creationTiming = 50;
		int difficultyCounter = 0;

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
			creationCounter++;
			difficultyCounter++;

			objData.position = { 0.0f, 350.0f };

			if (creationCounter >= creationTiming)
			{
				objData.QueueChildCreation(GameObjType::individual_shit, ControllerType::SHIT_CONTROLLER_FALL);
				creationCounter = 0;
			}

			if (difficultyCounter >= 35)
			{
				if (creationTiming >= 15)
				{
					creationTiming--;
				}
				
				difficultyCounter = 0;
			}
		}
	};
}