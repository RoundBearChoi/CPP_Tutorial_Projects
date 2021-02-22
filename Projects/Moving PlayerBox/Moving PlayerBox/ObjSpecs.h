#pragma once
#include "GameObjType.h"
#include "ControllerType.h"

namespace RB
{
	class ObjSpecs
	{
	public:
		GameObjType objType = GameObjType::NONE;
		ControllerType controllerType = ControllerType::NONE;

		ObjSpecs(GameObjType _objType, ControllerType _controllerType)
		{
			objType = _objType;
			controllerType = _controllerType;
		}
	};
}