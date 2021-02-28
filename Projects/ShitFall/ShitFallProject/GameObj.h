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
	private:
		Renderer renderer;

	public:
		ObjData data;
		StateController* ptrStateController = nullptr;

		GameObj(const ObjSpecs& specs)
		{
			IF_COUT{ std::cout << "construcing GameObj" << std::endl; }
			
			data.objWidth = specs.width;
			data.objHeight = specs.height;
			data.objType = specs.objType;
			data.offsetType = specs.offsetType;
			data.decalIndex = specs.decalIndex;
		}

		~GameObj()
		{
			IF_COUT{ std::cout << "destructing GameObj" << std::endl; }

			if (ptrStateController != nullptr)
			{
				delete ptrStateController;
			}
		}

		void Render(olc::PixelGameEngine* engine, olc::Decal* decal)
		{
			renderer.Render(engine, decal, data);
		}

		bool IsCollidingAgainst(GameObj* _target)
		{
			if (_target == nullptr)
			{
				return false;
			}

			if (_target->data.objWidth <= 0.0f || _target->data.objHeight <= 0.0f)
			{
				return false;
			}

			if (data.objWidth <= 0.0f || data.objHeight <= 0.0f)
			{
				return false;
			}

			olc::vf2d p1; //player top left position)
			p1.x = _target->data.position.x - (_target->data.objWidth / 2.0f);
			p1.y = _target->data.position.y - (_target->data.objHeight);

			olc::vf2d p2; //shit top left position
			p2.x = data.position.x - (data.objWidth / 2.0f);
			p2.y = data.position.y - (data.objHeight / 2.0f);

			if(p1.x < p2.x + data.objWidth && p1.x + _target->data.objWidth > p2.x)
			{
				return true;
			}

			return false;
		}

		int GetStateFrameCount()
		{
			if (ptrStateController != nullptr)
			{
				return ptrStateController->GetStateFrameCount();
			}
			else
			{
				return 0;
			}
		}
	};
}