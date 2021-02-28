#pragma once
#include "StateController.h"
#include "State.h"
#include "StateType.h"

#include "ShitGenerator.h"
#include "ShitPosition.h"
#include "ShitFall.h"
#include "ShitSplash.h"

namespace RB
{
	class ShitController : public StateController
	{
	public:
		ShitController(ObjData& objData, int _initialStateIndex)
		{
			IF_COUT{ std::cout << "constructing ShitController" << std::endl; }

			MakeTransition(objData, _initialStateIndex);
		}

		~ShitController() override
		{
			IF_COUT{ std::cout << "destructing ShitController" << std::endl; }

			delete currentState;
		}

		void MakeTransition(ObjData& objData, int index) override
		{
			delete currentState;
			currentStateIndex = index;

			if (index == (int)ShitStateType::GENERATOR)
			{
				currentState = stateCreator.CreateState<ShitGenerator>(objData);
			}
			else if (index == (int)ShitStateType::RANDOM_POSITION)
			{
				currentState = stateCreator.CreateState<ShitPosition>(objData);
			}
			else if (index == (int)ShitStateType::FALL)
			{
				currentState = stateCreator.CreateState<ShitFall>(objData);
			}
			else if (index == (int)ShitStateType::SHIT_SPLASH)
			{
				currentState = stateCreator.CreateState<ShitSplash>(objData);
			}
		}
	};
}