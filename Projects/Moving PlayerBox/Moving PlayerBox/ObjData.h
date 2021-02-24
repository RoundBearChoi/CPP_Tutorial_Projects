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
		int creationID = 0;

	public:
		olc::vf2d position = olc::vf2d(0.0f, 0.0f);
		GameObjType objType = GameObjType::NONE;

		~ObjData()
		{
			std::cout << "destructing ObjData - CreationID: " << creationID << std::endl;
		}
		
		void QueueChildCreation(GameObjType _objType, ControllerType _controllerType)
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

		void ClearChildQueues()
		{
			vecChildQueues.clear();
		}

		void SetCreationID(int _id)
		{
			std::cout << "setting ObjData CreationID: " << _id << std::endl;
			creationID = _id;
		}
	};
}