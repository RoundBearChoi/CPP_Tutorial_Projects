#pragma once
#include "ObjTag.h"

namespace RB
{
	class SlowUpdate
	{
	private:
		int counter = 0;
		bool canUpdate = false;
		int delayTime = 0;
		ObjTag targetTag = ObjTag::NONE;

	public:
		SlowUpdate(ObjTag _tag, int _targetDelay)
		{
			targetTag = _tag;
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

		void SetTargetType(ObjTag _targetTag)
		{
			targetTag = _targetTag;
		}

		ObjTag GetTargetType()
		{
			return targetTag;
		}
	};
}