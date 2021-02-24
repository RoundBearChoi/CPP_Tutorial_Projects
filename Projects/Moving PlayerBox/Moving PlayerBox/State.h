#pragma once
#include "olcPixelGameEngine.h"
#include "GameData.h"
#include "ObjData.h"

namespace RB
{
	class GameObjTree;

	class State
	{
	protected:
		int nextStateIndex = 0;
		int changeSceneIndex = 0;
		bool deleteObj = false;
		GameObjTree* ownerTree = nullptr;

	public:
		virtual void UpdateState(ObjData& objData, GameObjTree* tree, const GameData& gameData) = 0;

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
	};
}