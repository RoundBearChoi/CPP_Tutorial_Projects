#pragma once
#include "State.h"

namespace RB
{
	class PlayerIdle : public State
	{
	public:
		void UpdateState(InputData &_inputData, PositionalData &_positionalData) override
		{

		}
	};
}