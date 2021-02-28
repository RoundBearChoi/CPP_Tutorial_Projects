#pragma once
#include <any>
#include "GameObjType.h"
#include "OffsetType.h"

namespace RB
{
	class ObjSpecs
	{
	public:
		float width = 0.0f;
		float height = 0.0f;

		GameObjType objType = GameObjType::NONE;
		OffsetType offsetType = OffsetType::NONE;
		int decalIndex = -1;
	};
}