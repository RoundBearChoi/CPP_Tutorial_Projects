#pragma once
#include "ObjController.h"
#include "State.h"
#include "ShitGenerator.h"
#include "ShitPosition.h"
#include "ShitFall.h"

namespace RB
{
	class ShitGeneratorController : public ObjController
	{
	public:
		ShitGeneratorController(int _initialStateIndex)
		{
			IF_COUT{ std::cout << "constructing ShitGeneratorController" << std::endl; }
			
			MakeTransition(_initialStateIndex);
		}

		~ShitGeneratorController() override
		{
			IF_COUT{ std::cout << "destructing ShitGeneratorController" << std::endl; }

			delete currentState;
		}

		void MakeTransition(int index) override
		{
			if (index == (int)ShitStateType::GENERATOR)
			{
				CreateState<ShitGenerator>();
			}
		}
	};
}