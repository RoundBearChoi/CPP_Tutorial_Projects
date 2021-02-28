#pragma once
#include "GameData.h"
#include "State.h"

namespace RB
{
	class StateController
	{
	private:
		State* currentState = nullptr;

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
			State* newState = State::CreateState<T>(objData);

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

		State* GetNextState()
		{
			return currentState->nextState;
		}

		void MakeStateTransition()
		{
			State* nextState = currentState->nextState;

			if (nextState != nullptr)
			{
				delete currentState;
				currentState = nextState;
				currentState->nextState = nullptr;
			}
		}
	};
}