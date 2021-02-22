#pragma once
#include "ControllerType.h"
#include "PlayerController.h"
#include "ShitController.h"
#include "RenderOffsetType.h"
#include "ObjData.h"

namespace RB
{
	class GameObj
	{
	private:
		int typeID = 0;
		ObjController* ptrController = nullptr;
		std::vector<GameObj*> vecChildrenPtr;

	public:
		ObjData data;

		GameObj(int _typeID)
		{
			std::cout << "construcing GameObj - typeID: " << _typeID << std::endl;
			typeID = _typeID;
		}

		~GameObj()
		{
			std::cout << "destructing GameObj - typeID: " << typeID << std::endl;

			delete ptrController;

			for (int i = 0; i < vecChildrenPtr.size(); i++)
			{
				delete vecChildrenPtr[i];
			}
		}

		void SetController(int _index)
		{
			if (_index == (int)ControllerType::PLAYER_CONTROLLER)
			{
				ptrController = new PlayerController();
			}
			else if (_index == (int)ControllerType::SHIT_GENERATOR_CONTROLLER)
			{
				ptrController = new ShitController(true);
			}
		}

		ObjController* GetController()
		{
			return ptrController;
		}

		int GetTypeID()
		{
			return typeID;
		}

		void Render(olc::PixelGameEngine* engine, olc::Decal* decal, RenderOffsetType renderOffset)
		{
			olc::vf2d offset(0.0f, 0.0f);
			float decalWidth = (float)(decal->sprite->width);
			float decalHeight = (float)(decal->sprite->height);

			if (renderOffset == RenderOffsetType::NONE)
			{
				// do nothing
			}
			else if (renderOffset == RenderOffsetType::CENTER_CENTER)
			{
				offset.x = -(decalWidth / 2.0f);
				offset.y = -(decalHeight / 2.0f);
			}
			else if (renderOffset == RenderOffsetType::BOTTOM_CENTER)
			{
				offset.x = -(decalWidth / 2.0f);
				offset.y = -(decalHeight);
			}

			engine->DrawDecal(data.position + offset, decal);
		}

		void AddChild(int _typeID)
		{
			GameObj* child = new GameObj(_typeID);
			child->SetController((int)ControllerType::SHIT_GENERATOR_CONTROLLER);
			vecChildrenPtr.push_back(child);
		}
	};
}