#pragma once
#include "ObjData.h"
#include "State.h"

namespace RB
{
	class StateCreator
	{
	public:
		template<class T>
		State* CreateState(ObjData& objData)
		{
			//delete currentState;

			if (std::is_base_of<State, T>::value)
			{
				return new T(objData);
				//currentState = new T(objData);
				//currentStateIndex = _stateIndex;
			}
		}
	};
}