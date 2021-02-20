#pragma once
#include "UpdateData.h"

namespace RB
{
	class State
	{
	public:

		virtual void UpdateState(UpdateData &updateData) = 0;
		int* nextStatePtr = nullptr;

		virtual ~State()
		{

		}
	};
}