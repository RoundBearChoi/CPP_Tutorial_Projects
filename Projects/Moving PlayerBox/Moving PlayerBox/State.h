#pragma once
#include "VecData.h"
#include "InputData.h"

namespace RB
{
	class State
	{
	public:
		virtual void UpdateState(InputData &_inputData, VecData &vecData) = 0;
		int* nextStatePtr = nullptr;

		//unused for now
		virtual ~State()
		{

		}
	};
}