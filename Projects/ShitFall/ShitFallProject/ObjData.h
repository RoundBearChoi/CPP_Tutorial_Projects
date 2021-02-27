#pragma once
#include <vector>
#include "olcPixelGameEngine.h"
#include "ObjSpecs.h"
#include "DevSettings.h"
#include "SlowUpdateMessage.h"

namespace RB
{
	class ObjData
	{
	private:
		std::vector<ObjSpecs> vecChildQueues;
		std::vector<SlowUpdateMessage> vecSlowUpdateMessages;
		int creationID = 0;

	public:
		olc::vf2d position = olc::vf2d(0.0f, 0.0f);
		GameObjType objType = GameObjType::NONE;
		OffsetType offsetType = OffsetType::NONE;
		int debugDecalIndex = 0;
		float objWidth = 0.0f;
		float objHeight = 0.0f;
		bool collided = false;
		int nextStateIndex = 0;

		~ObjData()
		{
			IF_COUT{ std::cout << "destructing ObjData - CreationID: " << creationID << std::endl; }
		}
		
		void AddToCreationQueue(ObjSpecs _specs)
		{
			vecChildQueues.push_back(_specs);
		}

		int GetCreationQueueCount()
		{
			return vecChildQueues.size();
		}

		ObjSpecs GetCreationSpecs(int _index)
		{
			return vecChildQueues[_index];
		}

		void ClearChildQueues()
		{
			vecChildQueues.clear();
		}

		void SetCreationID(int _id)
		{
			IF_COUT{ std::cout << "setting ObjData CreationID: " << _id << std::endl; }
			
			creationID = _id;
		}

		void AddSlowMoMessage(SlowUpdateMessage& _message)
		{
			vecSlowUpdateMessages.push_back(_message);
		}

		int GetSlowMoMessageCount()
		{
			return vecSlowUpdateMessages.size();
		}

		SlowUpdateMessage GetSlowMoMessage(int _index)
		{
			return vecSlowUpdateMessages[_index];
		}

		void ClearSlowMoMessages()
		{
			vecSlowUpdateMessages.clear();
		}
	};
}