#pragma once
#include "ObjSpecs.h"
#include "OffsetType.h"
#include "ObjData.h"
#include "DevSettings.h"
#include "Renderer.h"
#include "StateController.h"

namespace RB
{
	class GameObj
	{
	public:
		ObjData data;
		Renderer renderer;
		StateController* ptrStateController = nullptr;

		GameObj(const ObjSpecs& specs)
		{
			IF_COUT{ std::cout << "construcing GameObj" << std::endl; }
			
			data.size.x = specs.width;
			data.size.y = specs.height;
			data.objTag = specs.objTag;
			data.offsetType = specs.offsetType;
			data.decalIndex = specs.decalIndex;

			renderer.SetObjData(&data);
		}

		~GameObj()
		{
			IF_COUT{ std::cout << "destructing GameObj" << std::endl; }

			if (ptrStateController != nullptr)
			{
				delete ptrStateController;
			}
		}

		bool IsCollidingAgainst(GameObj* _target)
		{
			if (_target == nullptr)
			{
				return false;
			}

			if (_target->data.size.x <= 0.0f || _target->data.size.y <= 0.0f)
			{
				return false;
			}

			if (data.size.x <= 0.0f || data.size.y <= 0.0f)
			{
				return false;
			}

			olc::vf2d p1; //player top left position)
			p1.x = _target->data.position.x - (_target->data.size.x / 2.0f);

			olc::vf2d p2; //shit top left position
			p2.x = data.position.x - (data.size.x / 2.0f);

			if(p1.x < p2.x + data.size.x && p1.x + _target->data.size.x > p2.x)
			{
				return true;
			}

			return false;
		}

		int GetStateFrameCount()
		{
			if (ptrStateController != nullptr)
			{
				return ptrStateController->currentState->GetFrameCount();
			}
			else
			{
				return 0;
			}
		}
	};
}