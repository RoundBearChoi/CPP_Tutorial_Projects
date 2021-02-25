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

		virtual void UpdateState(ObjData& objData, GameData& gameData) = 0;

		virtual ~State()
		{

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