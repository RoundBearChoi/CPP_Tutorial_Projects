#pragma once
#include "ObjSpecs.h"
#include "OffsetType.h"
#include "ObjData.h"

#include "TitleController.h"
#include "PressEnterController.h"
#include "DummyPlayerController.h"
#include "PlayerController.h"
#include "ShitGeneratorController.h"
#include "ShitFallController.h"

namespace RB
{
	class GameObj
	{
	private:
		std::vector<GameObj*> vecChildrenPtr;
		GameObj* parent = nullptr;

	public:
		ObjData data;
		ObjController* ptrController = nullptr;

		GameObj(ObjSpecs specs)
		{
			std::cout << "construcing GameObj" << std::endl;
			data.objType = specs.objType;
		}

		~GameObj()
		{
			std::cout << "destructing GameObj" << std::endl;

			if (ptrController != nullptr)
			{
				delete ptrController;
			}
		}

		void Render(olc::PixelGameEngine* engine, olc::Decal* decal, OffsetType renderOffset)
		{
			std::array<olc::vf2d, 4> points;

			if (renderOffset == OffsetType::NONE)
			{
				points[0] = { data.position.x, data.position.y };
				points[1] = { data.position.x, data.position.y + data.objHeight };
				points[2] = { data.position.x + data.objWidth, data.position.y + data.objHeight };
				points[3] = { data.position.x + data.objWidth, data.position.y };
			}
			else if (renderOffset == OffsetType::CENTER_CENTER)
			{
				olc::vf2d offset(0.0f, 0.0f);
				offset.x = -(data.objWidth / 2.0f);
				offset.y = -(data.objHeight / 2.0f);

				points[0] = { data.position.x - offset.x, data.position.y - offset.y };
				points[1] = { data.position.x - offset.x, data.position.y + offset.y };
				points[2] = { data.position.x + offset.x, data.position.y + offset.y };
				points[3] = { data.position.x + offset.x, data.position.y - offset.y };
			}
			else if (renderOffset == OffsetType::BOTTOM_CENTER)
			{
				olc::vf2d offset(0.0f, 0.0f);
				offset.x = -(data.objWidth / 2.0f);

				points[0] = { data.position.x - offset.x, data.position.y - data.objHeight };
				points[1] = { data.position.x - offset.x, data.position.y };
				points[2] = { data.position.x + offset.x, data.position.y };
				points[3] = { data.position.x + offset.x, data.position.y - data.objHeight };
			}

			engine->DrawWarpedDecal(decal, points);
		}

		void AddToHierarchy(GameObj* child)
		{
			child->parent = this;
			vecChildrenPtr.push_back(child);
		}

		void SetController(ControllerType _controllerType)
		{
			if (_controllerType == ControllerType::TITLE_CONTROLLER)
			{
				ptrController = new TitleController();
			}
			else if (_controllerType == ControllerType::PRESS_ENTER_CONTROLLER)
			{
				ptrController = new PressEnterController();
			}
			else if (_controllerType == ControllerType::DUMMY_PLAYER_CONTROLLER)
			{
				ptrController = new DummyPlayerController();
			}

			else if (_controllerType == ControllerType::PLAYER_CONTROLLER)
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

		std::vector<GameObj*>& GetChildren()
		{
			return vecChildrenPtr;
		}

		void ClearDestructableChildren()
		{
			std::vector<int> removables;

			for (int i = 0; i < vecChildrenPtr.size(); i++)
			{
				if (vecChildrenPtr[i]->ptrController->DestructIsQueued())
				{
					removables.push_back(i);
				}
			}

			for (int i = 0; i < removables.size(); i++)
			{
				vecChildrenPtr.erase(vecChildrenPtr.begin() + removables[i]);
			}
		}

		GameObj* GetParent()
		{
			return parent;
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
			if (ptrController != nullptr)
			{
				return ptrController->GetStateFrameCount();
			}
			else
			{
				return 0;
			}
		}
	};
}