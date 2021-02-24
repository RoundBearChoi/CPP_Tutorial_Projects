#pragma once
#include "GameObjType.h"
#include "ControllerType.h"

namespace RB
{
	class ObjSpecs
	{
	public:
		float width = 0.0f;
		float height = 0.0f;
		GameObjType objType = GameObjType::NONE;
		ControllerType controllerType = ControllerType::NONE;
	};
}