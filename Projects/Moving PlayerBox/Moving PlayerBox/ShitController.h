#pragma once
#include "ObjController.h"
#include "ShitState.h"

namespace RB
{
	class ShitController : public ObjController
	{
	public:
		ShitState* currentState = nullptr;
		int nextState = 0;

		~ShitController() override
		{
			std::cout << "destructing ShitController" << std::endl;
			delete currentState;
		}
	};
}