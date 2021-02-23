#pragma once
#include "olcPixelGameEngine.h"
#include "ObjSpecs.h"
#include <vector>

namespace RB
{
	class ObjData
	{
	private:
		std::vector<ObjSpecs> vecChildQueues;

	public:
		olc::vf2d position = olc::vf2d(0.0f, 0.0f);
		
		void QueueChild(GameObjType _objType, ControllerType _controllerType)
		{
			ObjSpecs specs{ _objType, _controllerType };
			vecChildQueues.push_back(specs);
		}

		int GetChildQueueCount()
		{
			return vecChildQueues.size();
		}

		ObjSpecs GetChildCreationSpecs(int _index)
		{
			return vecChildQueues[_index];
		}

		void ClearChildQueue()
		{
			vecChildQueues.clear();
		}
	};
}