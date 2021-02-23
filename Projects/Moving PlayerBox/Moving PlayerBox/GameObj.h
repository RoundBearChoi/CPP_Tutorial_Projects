#pragma once
#include "ObjSpecs.h"
#include "PlayerController.h"
#include "ShitGeneratorController.h"
#include "ShitFallController.h"
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

		GameObj(ObjSpecs specs)
		{
			std::cout << "construcing GameObj" << std::endl;
			objType = specs.objType;
		}

		~GameObj()
		{
			std::cout << "destructing GameObj" << std::endl;

			if (ptrController != nullptr)
			{
				delete ptrController;
			}
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

		void AddToHierarchy(GameObj* child)
		{
			vecChildrenPtr.push_back(child);
		}

		void SetController(ControllerType _controllerType)
		{
			if (_controllerType == ControllerType::PLAYER_CONTROLLER)
			{
				ptrController = new PlayerController();
			}
			else if (_controllerType == ControllerType::SHIT_CONTROLLER_GENERATOR)
			{
				ptrController = new ShitGeneratorController();
			}
			else if (_controllerType == ControllerType::SHIT_CONTROLLER_FALL)
			{
				ptrController = new ShitFallController();
			}
		}

		ObjController* GetController()
		{
			return ptrController;
		}

		std::vector<GameObj*>& GetChildren()
		{
			return vecChildrenPtr;
		}
	};
}