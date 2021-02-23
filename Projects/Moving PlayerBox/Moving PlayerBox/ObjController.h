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

	public:
		virtual void MakeTransition(int index) = 0;

		virtual ~ObjController()
		{
			std::cout << "destructing ObjController (virtual)" << std::endl;
		}

		void UpdateObj(ObjData& objData, const GameData& gameData)
		{
			currentState->UpdateState(objData, gameData);
		}

		template<class T>
		void CreateState()
		{
			delete currentState;

			if (std::is_base_of<State, T>::value)
			{
				currentState = new T();
			}
		}

		int NextStateIndex()
		{
			return currentState->GetNextStateIndex();
		}

		int NextSceneIndex()
		{
			return currentState->GetNextSceneIndex();
		}

		bool DestructIsQueued()
		{
			return currentState->DeleteObj();
		}
	};
}