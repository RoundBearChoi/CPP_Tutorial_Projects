#pragma once
#include "ObjController.h"
#include "State.h"
#include "ShitStateType.h"
#include "ShitGenerator.h"
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
				MakeTransition((int)ShitStateType::FALL);
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
			else if (index == (int)ShitStateType::FALL)
			{
				CreateState<ShitFall>();
			}
		}

		virtual bool MakeChildObj() override
		{
			return false;

			//if (currentState->testing == 1)
			//{
			//	currentState->testing = 0;
			//	return true;
			//}
			//else
			//{
			//	return false;
			//}
		}
	};
}