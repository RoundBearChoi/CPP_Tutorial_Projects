#pragma once

namespace RB
{
	class ObjSpecs
	{
	public:
		int nObjType = 0;
		int nControllerType = 0;

		ObjSpecs(int _objTypeIndex, int _controllerIndex)
		{
			nObjType = _objTypeIndex;
			nControllerType = _controllerIndex;
		}
	};
}