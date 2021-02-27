#pragma once
#include "GameObjType.h"
#include "ControllerType.h"
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

		ControllerType controllerType = ControllerType::NONE;
		int initialStateIndex = 0;
	};
}