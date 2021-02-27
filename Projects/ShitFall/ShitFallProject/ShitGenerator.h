#pragma once
#include "State.h"
#include "GameObjType.h"
#include "ControllerType.h"

namespace RB
{
	class ShitGenerator : public State
	{
	private:
		int creationTiming = 50;
		int difficultyCounter = 0;

	public:
		ShitGenerator(ObjData& objData)
		{
			IF_COUT
			{
				std::cout << std::endl;
				std::cout << "constructing State: ShitGenerator" << std::endl;
			}

			objData.position = { 0.0f, 350.0f };
		}

		~ShitGenerator()
		{
			IF_COUT
			{
				std::cout << std::endl;
				std::cout << "destructing State: ShitGenerator" << std::endl;
			}
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			frameCount++;
			difficultyCounter++;

			if (frameCount >= creationTiming)
			{
				QueueGenerate(objData);
				frameCount = 0;
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

		void QueueGenerate(ObjData& objData)
		{
			ObjSpecs specs;
			specs.width = 37.0f;
			specs.height = 37.0f;
			specs.objType = GameObjType::individual_shit;
			specs.offsetType = OffsetType::CENTER_CENTER;
			specs.debugDecalIndex = (int)GameSpriteType::shit_box32x32;
			specs.controllerType = ControllerType::SHIT_CONTROLLER;
			specs.initialStateIndex = (int)ShitStateType::RANDOM_POSITION;

			objData.AddToCreationQueue(specs);
		}
	};
}