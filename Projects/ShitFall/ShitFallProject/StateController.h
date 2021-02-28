#pragma once
#include "GameData.h"
#include "State.h"
#include "StateCreator.h"

namespace RB
{
	class StateController
	{
	protected:
		State* currentState = nullptr;
		int currentStateIndex = 0;
		StateCreator stateCreator;

	public:
		virtual void MakeTransition(ObjData& objData, int index) = 0;

		virtual ~StateController()
		{

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

		int GetCurrentStateIndex()
		{
			return currentStateIndex;
		}
	};
}