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
		int typeIndex = 0;
		ObjController* ptrController = nullptr;
		std::vector<GameObj*> vecChildrenPtr;

	public:
		ObjData data;

		GameObj(int _typeIndex)
		{
			std::cout << "construcing GameObj - typeID: " << _typeIndex << std::endl;
			typeIndex = _typeIndex;
		}

		~GameObj()
		{
			std::cout << "destructing GameObj - typeID: " << typeIndex << std::endl;

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
			return typeIndex;
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

		void AddChild(int _typeIndex, int _controllerIndex)
		{
			GameObj* child = new GameObj(_typeIndex);

			if (_controllerIndex != 0)
			{
				child->SetController(_controllerIndex);
			}
			
			vecChildrenPtr.push_back(child);
		}
	};
}