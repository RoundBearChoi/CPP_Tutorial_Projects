#pragma once
#include "olcPixelGameEngine.h"
#include "GameData.h"
#include "ObjData.h"

namespace RB
{
	class State
	{
	protected:
		int changeSceneIndex = 0;
		int frameCount = 0;
		bool deleteObj = false;

	public:
		virtual void UpdateState(ObjData& objData, GameData& gameData) = 0;

		virtual ~State()
		{

		}

		int GetNextScene()
		{
			return changeSceneIndex;
		}

		bool DeleteObj()
		{
			return deleteObj;
		}

		int GetFrameCount()
		{
			return frameCount;
		}
	};
}