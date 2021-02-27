#pragma once
#include "GameObjType.h"

namespace RB
{
	class SlowUpdateMessage
	{
	public:
		GameObjType targetType = GameObjType::NONE;
		int targetFrameDelay = 0;
	};
}