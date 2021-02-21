#pragma once
#include "ObjController.h"
#include "State.h"
#include "ShitStateType.h"
#include "ShitFall.h"

namespace RB
{
	class ShitController : public ObjController
	{
	public:
		ShitController()
		{
			std::cout << "constructing ShitController" << std::endl;

			MakeTransition((int)ShitStateType::FALL);
		}

		~ShitController() override
		{
			std::cout << "destructing ShitController" << std::endl;
			delete currentState;
		}

		void MakeTransition(int index) override
		{
			if (index == (int)ShitStateType::FALL)
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