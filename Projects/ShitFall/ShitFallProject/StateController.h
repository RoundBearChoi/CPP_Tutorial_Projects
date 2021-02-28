#pragma once
#include "GameData.h"
#include "State.h"

namespace RB
{
	class StateController
	{
	private:
		State* currentState = nullptr;
		State* prevState = nullptr;

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
		void CreateState()
		{
			State* newState = State::CreateState<T>();

			if (newState != nullptr)
			{
				delete currentState;
				currentState = newState;
			}
		}

		void UpdateObj(ObjData& objData, GameData& gameData)
		{
			if (prevState == nullptr || prevState != currentState)
			{
				currentState->OnEnter(objData, gameData);
			}

			currentState->UpdateState(objData, gameData);

			prevState = currentState;
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