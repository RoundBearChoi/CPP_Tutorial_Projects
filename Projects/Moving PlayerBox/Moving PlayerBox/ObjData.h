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
		float width = 0.0f;
		float height = 0.0f;

	public:
		olc::vf2d position = olc::vf2d(0.0f, 0.0f);
		GameObjType objType = GameObjType::NONE;

		~ObjData()
		{
			std::cout << "destructing ObjData - CreationID: " << creationID << std::endl;
		}
		
		void QueueChildCreation(ObjSpecs _specs)
		{
			vecChildQueues.push_back(_specs);
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