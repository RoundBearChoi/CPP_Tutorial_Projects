#pragma once
#include "UpdateData.h"

namespace RB
{
	class State
	{
	protected:
		std::string name = "unassigned";

	public:
		virtual void UpdateState(UpdateData &updateData) = 0;
		int* nextStatePtr = nullptr;

		State()
		{
			std::cout << std::endl;
			std::cout << "constructing State" << std::endl;
		}

		virtual ~State()
		{
			std::cout << "destructing State" << std::endl;
		}
	};
}