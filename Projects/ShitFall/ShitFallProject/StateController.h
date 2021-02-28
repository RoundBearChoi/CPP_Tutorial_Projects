#pragma once
#include "GameData.h"
#include "State.h"
#include "StateCreator.h"

namespace RB
{
	class StateController
	{
	private:
		State* currentState = nullptr;
		StateCreator stateCreator;
		//int currentStateIndex = 0;

	public:
		StateController()
		{
			IF_COUT{ std::cout << "constructing StateController" << std::endl; }
		}

		~StateController()
		{
			IF_COUT{ std::cout << "destructing StateController" << std::endl; }

			delete currentState;
		}

		template<class T>
		void CreateState(ObjData& objData)
		{
			State* newState = stateCreator.CreateState<T>(objData);

			if (newState != nullptr)
			{
				delete currentState;
				//currentStateIndex = index;

				currentState = newState;
			}
		}

		void UpdateObj(ObjData& objData, GameData& gameData)
		{
			currentState->UpdateState(objData, gameData);
		}

		bool DeleteObj()
		{
			return currentState->DeleteObj();
		}

		int GetStateFrameCount()
		{
			return currentState->GetFrameCount();
		}

		AnimationData* GetStateRenderData()
		{
			if (currentState != nullptr)
			{
				return currentState->GetRenderData();
			}
			else
			{
				return nullptr;
			}
		}

		//int GetCurrentStateIndex()
		//{
		//	return currentStateIndex;
		//}
	};
}