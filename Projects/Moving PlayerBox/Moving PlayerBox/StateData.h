#pragma once
#include "State.h"

namespace RB
{
	class StateData
	{
	public:
		State* currentState = nullptr;
		int nextState = 0;

		~StateData()
		{
			delete currentState;
		}

		template<class T>
		void CreateState()
		{
			delete currentState;

			if (std::is_base_of<State, T>::value)
			{
				currentState = new T();
				currentState->nextStatePtr = &nextState;
			}
		}
	};
}