#include "GameObj.h"

namespace RB
{
	GameObj::GameObj(ObjSpecs specs)
	{
		std::cout << "construcing GameObj - typeIndex: " << (int)specs.objType << std::endl;
		objType = specs.objType;
	}

	GameObj::~GameObj()
	{
		std::cout << "destructing GameObj - typeIndex: " << (int)objType << std::endl;

		if (ptrController != nullptr)
		{
			delete ptrController;
		}
	}

	bool GameObj::IsObjType(GameObjType _objType)
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

	void GameObj::Render(olc::PixelGameEngine* engine, olc::Decal* decal, RenderOffsetType renderOffset)
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

	void GameObj::AddToHierarchy(GameObj* child)
	{
		vecChildrenPtr.push_back(child);
	}

	void GameObj::SetController(ControllerType _controllerType)
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

	ObjController* GameObj::GetController()
	{
		return ptrController;
	}
}