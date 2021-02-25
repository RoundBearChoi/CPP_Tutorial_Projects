#pragma once
#include <vector>
#include "olcPixelGameEngine.h"
#include "ObjSpecs.h"

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
		OffsetType offsetType = OffsetType::NONE;
		float objWidth = 0.0f;
		float objHeight = 0.0f;
		bool collided = false;
		int nextStateIndex = 0;

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