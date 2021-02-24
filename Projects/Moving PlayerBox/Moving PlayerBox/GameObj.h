#pragma once
#include "ObjSpecs.h"
#include "RenderOffsetType.h"
#include "ObjData.h"
#include "Rect.h"

#include "TitleController.h"
#include "DummyPlayerController.h"
#include "PlayerController.h"
#include "ShitGeneratorController.h"
#include "ShitFallController.h"

namespace RB
{
	class GameObj
	{
	private:
		ObjController* ptrController = nullptr;
		std::vector<GameObj*> vecChildrenPtr;
		GameObj* parent = nullptr;

	public:
		ObjData data;

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

		void Render(olc::PixelGameEngine* engine, olc::Decal* decal, RenderOffsetType renderOffset)
		{
			std::array<olc::vf2d, 4> points;

			if (renderOffset == RenderOffsetType::NONE)
			{
				points[0] = { data.position.x, data.position.y };
				points[1] = { data.position.x, data.position.y + data.objHeight };
				points[2] = { data.position.x + data.objWidth, data.position.y + data.objHeight };
				points[3] = { data.position.x + data.objWidth, data.position.y };
			}
			else if (renderOffset == RenderOffsetType::CENTER_CENTER)
			{
				olc::vf2d offset(0.0f, 0.0f);
				offset.x = -(data.objWidth / 2.0f);
				offset.y = -(data.objHeight / 2.0f);

				points[0] = { data.position.x - offset.x, data.position.y - offset.y };
				points[1] = { data.position.x - offset.x, data.position.y + offset.y };
				points[2] = { data.position.x + offset.x, data.position.y + offset.y };
				points[3] = { data.position.x + offset.x, data.position.y - offset.y };
			}
			else if (renderOffset == RenderOffsetType::BOTTOM_CENTER)
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
			else if (_controllerType == ControllerType::TITLE_PRESSENTER_CONTROLLER)
			{

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

		ObjController* GetController()
		{
			return ptrController;
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
				if (vecChildrenPtr[i]->GetController()->DestructIsQueued())
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

			Rect rect1; //player (pivot is offset)
			rect1.x = _target->data.position.x;
			rect1.y = _target->data.position.y - _target->data.objHeight / 2.0f;
			rect1.width = _target->data.objWidth;
			rect1.height = _target->data.objHeight;

			Rect rect2; //shit
			rect2.x = data.position.x;
			rect2.y = data.position.y;
			rect2.width = data.objWidth;
			rect2.height = data.objHeight;

			//axis-aligned bounding box
			if(rect1.x < rect2.x + rect2.width && rect1.x + rect1.width > rect2.x)
			{
				if (rect1.y < rect2.y + rect2.height && rect1.y + rect1.height > rect2.y)
				{
					return true;
				}
			}

			return false;
		}
	};
}