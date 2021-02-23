#pragma once
#include <vector>
#include <iostream>
#include "GameObj.h"
#include "ObjSpecs.h"

namespace RB
{
	class GameObjTree
	{
	private:
		std::vector<GameObj*> vecAllObjs;

	public:
		GameObjTree()
		{
			std::cout << "constructing GameObjTree" << std::endl;
		}

		~GameObjTree()
		{
			std::cout << "destructing GameObjTree" << std::endl;

			for (int i = 0; i < vecAllObjs.size(); i++)
			{
				delete vecAllObjs[i];
			}
		}

		void UpdateAll(const GameData& gameData)
		{
			for (int i = 0; i < vecAllObjs.size(); i++)
			{
				GameObj* obj = vecAllObjs[i];
				ObjController* controller = vecAllObjs[i]->GetController();

				if (controller != nullptr)
				{
					//update every obj
					controller->UpdateObj(obj->data, gameData);
					
					//check child creation
					CreateChildren(obj);

					//check transition
					int nextState = obj->GetController()->NextStateIndex();

					if (nextState != 0)
					{
						controller->MakeTransition(nextState);
					}
				}
			}
		}

		void CreateChildren(GameObj* obj)
		{
			for (int i = 0; i < obj->data.GetChildQueueCount(); i++)
			{
				ObjSpecs specs = obj->data.GetChildCreationSpecs(i);
				GameObj* child = new GameObj(specs);

				if (specs.controllerType != ControllerType::NONE)
				{
					child->SetController(specs.controllerType);
				}

				vecAllObjs.push_back(child);
				obj->AddToHierarchy(child);
			}

			obj->data.ClearChildQueues();
		}

		void CreateObj(ObjSpecs specs)
		{
			vecAllObjs.push_back(new GameObj(specs));

			if (specs.controllerType != ControllerType::NONE)
			{
				vecAllObjs[vecAllObjs.size() - 1]->SetController(specs.controllerType);
			}
		}

		GameObj* GetObjType(GameObjType _objType)
		{
			for (int i = 0; i < vecAllObjs.size(); i++)
			{
				if (vecAllObjs[i]->IsObjType(_objType))
				{
					return vecAllObjs[i];
				}
			}
			
			return nullptr;
		}
	};
}