#pragma once
#include "ObjTag.h"
#include "OffsetType.h"

namespace RB
{
	class ObjSpecs
	{
	public:
		float width = 0.0f;
		float height = 0.0f;

		ObjTag objTag = ObjTag::NONE;
		OffsetType offsetType = OffsetType::NONE;
		int decalIndex = -1;
	};
}