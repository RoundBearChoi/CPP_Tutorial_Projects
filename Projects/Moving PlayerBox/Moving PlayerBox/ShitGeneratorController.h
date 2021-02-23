#pragma once
#include "ObjController.h"
#include "State.h"
#include "ShitStateType.h"
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
			std::cout << "constructing ShitGeneratorController" << std::endl;

			MakeTransition((int)ShitStateType::GENERATOR);
		}

		~ShitGeneratorController() override
		{
			std::cout << "destructing ShitGeneratorController" << std::endl;
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