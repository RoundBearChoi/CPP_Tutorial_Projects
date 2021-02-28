#pragma once
#include "olcPixelGameEngine.h"
#include "GameData.h"
#include "ObjData.h"
#include "StateAnimation.h"

namespace RB
{
	class State
	{
	protected:
		int frameCount = 0;
		bool deleteObj = false;

	public:
		StateAnimation stateAnimation;
		State* nextState = nullptr;

		virtual void UpdateState(ObjData& objData, GameData& gameData) = 0;

		virtual ~State()
		{

		}

		template<class T>
		static State* CreateState(ObjData& objData)
		{
			if (std::is_base_of<State, T>::value)
			{
				return new T(objData);
			}
			else
			{
				return nullptr;
			}
		}

		bool DeleteObj()
		{
			return deleteObj;
		}

		int GetFrameCount()
		{
			return frameCount;
		}

		AnimationData* GetRenderData()
		{
			return stateAnimation.GetRenderData(stateAnimation.GetDecalIndex());
		}
	};
}