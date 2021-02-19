#pragma once
#include "PositionalData.h"
#include "InputData.h"

namespace RB
{
	class State
	{
	public:
		virtual void UpdateState(InputData &_inputData, PositionalData &_positionalData) = 0;

		//unused for now
		virtual ~State()
		{

		}
	};
}