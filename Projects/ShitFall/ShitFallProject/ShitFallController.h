#pragma once
#include "ObjController.h"
#include "State.h"
#include "ShitGenerator.h"
#include "ShitPosition.h"
#include "ShitFall.h"
#include "ShitSplash.h"

namespace RB
{
	class ShitFallController : public ObjController
	{
	public:
		ShitFallController(int _initialStateIndex)
		{
			IF_COUT{ std::cout << "constructing ShitFallController" << std::endl; }
			
			MakeTransition(_initialStateIndex);
		}

		~ShitFallController() override
		{
			IF_COUT{ std::cout << "destructing ShitFallController" << std::endl; }

			delete currentState;
		}

		void MakeTransition(int index) override
		{
			if (index == (int)ShitStateType::RANDOM_POSITION)
			{
				CreateState<ShitPosition>();
			}
			else if (index == (int)ShitStateType::FALL)
			{
				CreateState<ShitFall>();
			}
			else if (index == (int)ShitStateType::SHIT_SPLASH)
			{
				CreateState<ShitSplash>();
			}
		}
	};
}