#pragma once
#include "GameData.h"
#include "State.h"

namespace RB
{
	class StateController
	{
	private:
		
		State* prevState = nullptr;

	public:
		State* currentState = nullptr;

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

		AnimationData* GetStateRenderData(bool update, bool skipUpdate)
		{
			if (currentState != nullptr)
			{
				return currentState->stateAnimation.GetRenderData(update, skipUpdate);
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