#pragma once
#include <iostream>
#include "GameData.h"
#include "State.h"

namespace RB
{
	class ObjController
	{
	protected:
		State* currentState = nullptr;
		int nextState = 0;

	public:
		virtual void UpdateObj(olc::vf2d& position, const GameData& updateData) = 0;
		virtual void CheckNextTransition() = 0;
		virtual bool MakeTransition(int index) = 0;
		virtual bool MakeChildObj() = 0;

		virtual ~ObjController()
		{
			std::cout << "destructing ObjController (virtual)" << std::endl;
		}

		template<class T>
		bool CreateState()
		{
			delete currentState;

			if (std::is_base_of<State, T>::value)
			{
				currentState = new T();
				currentState->nextStatePtr = &nextState;
				return true;
			}

			return false;
		}
	};
}