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

		void SetCurrentState(State* state)
		{
			currentState = state;
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

		AnimationData* GetStateRenderData(bool update, bool skipUpdate)
		{
			if (currentState != nullptr)
			{
				return currentState->GetRenderData(update, skipUpdate);
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

		std::vector<State*>& GetCreationQueues()
		{
			return currentState->vecCreateObjs;
		}

		std::vector<ObjSpecs>& GetCreationSpecs()
		{
			return currentState->vecCreationSpecs;
		}

		template <class T>
		bool CurrentStateIs()
		{
			//if (typeid(T).name() == typeid(*currentState).name())
			if (typeid(T) == typeid(*currentState))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	};
}