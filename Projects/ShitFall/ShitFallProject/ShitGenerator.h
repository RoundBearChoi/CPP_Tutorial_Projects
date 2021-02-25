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

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			creationCounter++;
			difficultyCounter++;

			objData.position = { 0.0f, 350.0f };

			if (creationCounter >= creationTiming)
			{
				ObjSpecs specs;
				specs.width = 32.0f;
				specs.height = 32.0f;
				specs.objType = GameObjType::individual_shit;
				specs.offsetType = OffsetType::CENTER_CENTER;
				specs.debugDecalIndex = (int)GameSpriteType::shit_box32x32;
				specs.controllerType = ControllerType::SHIT_CONTROLLER_FALL;
				objData.QueueChildCreation(specs);
				creationCounter = 0;
			}

			if (difficultyCounter >= 35)
			{
				if (creationTiming >= 10)
				{
					creationTiming--;
				}
				
				difficultyCounter = 0;
			}
		}
	};
}