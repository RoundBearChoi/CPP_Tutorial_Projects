#pragma once
#include "State.h"
#include "ObjTag.h"

namespace RB
{
	class ShitPosition;

	class ShitGenerator : public State
	{
	private:
		int creationTiming = 50;
		int difficultyCounter = 0;

	public:
		ShitGenerator()
		{
			IF_COUT
			{
				std::cout << std::endl;
				std::cout << "constructing State: ShitGenerator" << std::endl;
			}
		}

		~ShitGenerator()
		{
			IF_COUT
			{
				std::cout << std::endl;
				std::cout << "destructing State: ShitGenerator" << std::endl;
			}
		}

		void OnEnter(ObjData& objData, GameData& gameData) override
		{
			objData.position = { 0.0f, 350.0f };
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
			State* newState = State::CreateState<ShitPosition>();
			vecCreateObjs.push_back(newState);
			
			ObjSpecs specs;
			specs.width = 37.0f;
			specs.height = 37.0f;
			specs.objTag = ObjTag::SHIT;
			specs.offsetType = OffsetType::CENTER_CENTER;
			specs.decalIndex = (int)GameSpriteType::shit_box32x32;
			vecCreationSpecs.push_back(specs);
		}
	};
}