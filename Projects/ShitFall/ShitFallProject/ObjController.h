#pragma once
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

		}

		void UpdateObj(ObjData& objData, GameData& gameData)
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
	};
}