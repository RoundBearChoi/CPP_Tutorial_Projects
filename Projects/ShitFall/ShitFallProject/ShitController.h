#pragma once
#include "ObjController.h"
#include "State.h"
#include "StateType.h"

#include "ShitGenerator.h"
#include "ShitPosition.h"
#include "ShitFall.h"
#include "ShitSplash.h"

namespace RB
{
	class ShitController : public ObjController
	{
	public:
		ShitController(int _initialStateIndex, ObjData& objData)
		{
			IF_COUT{ std::cout << "constructing ShitController" << std::endl; }

			MakeTransition(_initialStateIndex, objData);
		}

		~ShitController() override
		{
			IF_COUT{ std::cout << "destructing ShitController" << std::endl; }

			delete currentState;
		}

		void MakeTransition(int index, ObjData& objData) override
		{
			if (index == (int)ShitStateType::GENERATOR)
			{
				CreateState<ShitGenerator>(index, objData);
			}
			else if (index == (int)ShitStateType::RANDOM_POSITION)
			{
				CreateState<ShitPosition>(index, objData);
			}
			else if (index == (int)ShitStateType::FALL)
			{
				CreateState<ShitFall>(index, objData);
			}
			else if (index == (int)ShitStateType::SHIT_SPLASH)
			{
				CreateState<ShitSplash>(index, objData);
			}
		}
	};
}