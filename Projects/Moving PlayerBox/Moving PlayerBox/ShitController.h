#pragma once
#include "ObjController.h"
#include "State.h"
#include "ShitStateType.h"
#include "ShitGenerator.h"
#include "ShitPosition.h"
#include "ShitFall.h"

namespace RB
{
	class ShitController : public ObjController
	{
	public:
		ShitController(bool isGenerator = false)
		{
			std::cout << "constructing ShitController" << std::endl;

			if (isGenerator)
			{
				MakeTransition((int)ShitStateType::GENERATOR);
			}
			else
			{
				MakeTransition((int)ShitStateType::POSITION);
			}
		}

		~ShitController() override
		{
			std::cout << "destructing ShitController" << std::endl;
			delete currentState;
		}

		void MakeTransition(int index) override
		{
			if (index == (int)ShitStateType::GENERATOR)
			{
				CreateState<ShitGenerator>();
			}
			else if (index == (int)ShitStateType::POSITION)
			{
				CreateState<ShitPosition>();
			}
			else if (index == (int)ShitStateType::FALL)
			{
				CreateState<ShitFall>();
			}
		}
	};
}