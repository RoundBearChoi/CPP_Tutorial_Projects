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
		ShitGeneratorController()
		{
			IF_COUT{ std::cout << "constructing ShitGeneratorController" << std::endl; }
			
			MakeTransition((int)ShitStateType::GENERATOR);
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