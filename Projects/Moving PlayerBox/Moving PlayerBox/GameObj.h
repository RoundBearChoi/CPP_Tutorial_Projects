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
		GameObjType objType = GameObjType::NONE;
		ObjController* ptrController = nullptr;
		std::vector<GameObj*> vecChildrenPtr;

	public:
		ObjData data;

		GameObj(GameObjType _objType)
		{
			std::cout << "construcing GameObj - typeID: " << (int)_objType << std::endl;
			objType = _objType;
		}

		~GameObj()
		{
			std::cout << "destructing GameObj - typeID: " << (int)objType << std::endl;

			delete ptrController;

			for (int i = 0; i < vecChildrenPtr.size(); i++)
			{
				delete vecChildrenPtr[i];
			}
		}

		void SetController(ControllerType _controllerType)
		{
			if (_controllerType == ControllerType::PLAYER_CONTROLLER)
			{
				ptrController = new PlayerController();
			}
			else if (_controllerType == ControllerType::SHIT_GENERATOR_CONTROLLER)
			{
				ptrController = new ShitController(true);
			}
		}

		ObjController* GetController()
		{
			return ptrController;
		}

		bool IsObjType(GameObjType _objType)
		{
			if (objType == _objType)
			{
				return true;
			}
			else
			{
				return false;
			}
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

		void AddChild(GameObjType _objType, ControllerType _controllerType)
		{
			GameObj* child = new GameObj(_objType);

			if (_controllerType != ControllerType::NONE)
			{
				child->SetController(_controllerType);
			}
			
			vecChildrenPtr.push_back(child);
		}
	};
}