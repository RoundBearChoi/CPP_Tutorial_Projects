#pragma once
#include "GameObjType.h"

namespace RB
{
	class SlowUpdate
	{
	private:
		int counter = 0;
		bool canUpdate = false;
		int delayTime = 0;
		GameObjType targetObjType = GameObjType::NONE;

	public:
		SlowUpdate(GameObjType _targetType, int _targetDelay)
		{
			targetObjType = _targetType;
			delayTime = _targetDelay;
		}

		void UpdateSlowMoCounter()
		{
			counter++;

			if (counter >= delayTime)
			{
				counter = 0;
				canUpdate = true;
			}
			else
			{
				canUpdate = false;
			}
		}

		bool CanUpdate()
		{
			return canUpdate;
		}

		void SetDelayTime(int _delayFrames)
		{
			delayTime = _delayFrames;
		}

		void SetTargetType(GameObjType _targetType)
		{
			targetObjType = _targetType;
		}

		GameObjType GetTargetType()
		{
			return targetObjType;
		}
	};
}