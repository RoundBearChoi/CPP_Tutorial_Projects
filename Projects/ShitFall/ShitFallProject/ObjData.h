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
		std::vector<SlowUpdateMessage> vecSlowUpdateMessages;
		int creationID = 0;

	public:
		olc::vf2d position = olc::vf2d(0.0f, 0.0f);
		olc::vf2d size = olc::vf2d(0.0f, 0.0f);
		ObjTag objTag = ObjTag::NONE;
		OffsetType offsetType = OffsetType::NONE;
		int decalIndex = 0;
		bool collided = false;

		~ObjData()
		{
			IF_COUT{ std::cout << "destructing ObjData - CreationID: " << creationID << std::endl; }
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