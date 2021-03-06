#pragma once
#include "olcPixelGameEngine.h"
#include "GameData.h"
#include "ObjData.h"
#include "AnimationController.h"
#include "TransitionDelayTable.h"

namespace RB
{
	class State
	{
	protected:
		int frameCount = 0;
		bool deleteObj = false;

	public:
		AnimationController animationController;
		State* nextState = nullptr;
		std::vector<State*> vecCreateObjs;
		std::vector<ObjSpecs> vecCreationSpecs;

		virtual void OnEnter(ObjData& objData, GameData& gameData) = 0;
		virtual void UpdateState(ObjData& objData, GameData& gameData) = 0;

		virtual ~State()
		{

		}

		template<class T>
		static State* CreateState()
		{
			if (std::is_base_of<State, T>::value)
			{
				return new T();
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
	};
}