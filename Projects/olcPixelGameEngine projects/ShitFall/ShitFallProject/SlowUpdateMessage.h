#pragma once
#include "ObjTag.h"

namespace RB
{
	class SlowUpdateMessage
	{
	public:
		ObjTag targetType = ObjTag::NONE;
		int targetFrameDelay = 0;
	};
}