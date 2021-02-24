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
		int changeSceneIndex = 0;
		int frameCount = 0;
		bool deleteObj = false;
		bool bColliding = false;

	public:
		virtual void UpdateState(ObjData& objData, GameData& gameData) = 0;

		virtual ~State()
		{

		}

		int GetNextStateIndex()
		{
			return nextStateIndex;
		}

		int GetNextSceneIndex()
		{
			return changeSceneIndex;
		}

		bool DeleteObj()
		{
			return deleteObj;
		}

		void SetCollisionFlag()
		{
			bColliding = true;
		}

		void ClearCollisionFlag()
		{
			bColliding = false;
		}
	};
}