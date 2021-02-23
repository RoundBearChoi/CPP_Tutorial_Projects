#pragma once
#include "olcPixelGameEngine.h"
#include "GameData.h"
#include "ObjData.h"

namespace RB
{
	class State
	{
	protected:
		int nextStateIndex = 0;
		bool deleteObj = false;

	public:
		virtual void UpdateState(ObjData& objData, const GameData& gameData) = 0;

		virtual ~State()
		{

		}

		int GetNextStateIndex()
		{
			return nextStateIndex;
		}

		bool DeleteObj()
		{
			return deleteObj;
		}
	};
}