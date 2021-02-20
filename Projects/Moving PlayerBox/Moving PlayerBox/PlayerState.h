#pragma once
#include "UpdateData.h"

namespace RB
{
	class PlayerState
	{
	protected:
		std::string name = "unassigned";

	public:
		virtual void UpdateState(UpdateData &updateData) = 0;
		int* nextStatePtr = nullptr;

		PlayerState()
		{
			std::cout << std::endl;
			std::cout << "constructing State" << std::endl;
		}

		virtual ~PlayerState()
		{
			std::cout << "destructing State" << std::endl;
		}
	};
}