#pragma once
#include "GameData.h"
#include "State.h"

namespace RB
{
	class StateController
	{
	protected:
		State* currentState = nullptr;
		int currentStateIndex = 0;

	public:
		virtual void MakeTransition(ObjData& objData, int index) = 0;

		virtual ~StateController()
		{

		}

		void UpdateObj(ObjData& objData, GameData& gameData)
		{
			currentState->UpdateState(objData, gameData);
		}

		template<class T>
		void CreateState(ObjData& objData, int _stateIndex)
		{
			delete currentState;

			if (std::is_base_of<State, T>::value)
			{
				currentState = new T(objData);
				currentStateIndex = _stateIndex;
			}
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

		int GetCurrentStateIndex()
		{
			return currentStateIndex;
		}
	};
}