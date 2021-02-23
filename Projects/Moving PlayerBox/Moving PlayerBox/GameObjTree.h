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
		std::vector<GameObj*> vecObjRootsPtr;

	public:
		GameObjTree()
		{
			std::cout << "constructing GameObjTree" << std::endl;
		}

		~GameObjTree()
		{
			std::cout << "destructing GameObjTree" << std::endl;

			for (int i = 0; i < vecObjRootsPtr.size(); i++)
			{
				delete vecObjRootsPtr[i];
			}
		}

		void UpdateAll(const GameData& gameData)
		{
			for (int i = 0; i < vecObjRootsPtr.size(); i++)
			{
				ObjController* controller = vecObjRootsPtr[i]->GetController();

				if (controller != nullptr)
				{
					controller->UpdateObj(vecObjRootsPtr[i]->data, gameData);
					
					int nextState = vecObjRootsPtr[i]->GetController()->NextStateIndex();

					if (nextState != 0)
					{
						controller->MakeTransition(nextState);
					}
					
					//add child from info
					int Queues = vecObjRootsPtr[i]->data.GetChildQueues();

					for (int child = 0; child < Queues; child++)
					{
						vecObjRootsPtr[i]->data.RemoveQueue();
					}
				}
			}
		}

		void CreateObj(ObjSpecs specs, GameObj* parent = nullptr)
		{
			if (parent == nullptr)
			{
				vecObjRootsPtr.push_back(new GameObj(specs));

				if (specs.controllerType != ControllerType::NONE)
				{
					vecObjRootsPtr[vecObjRootsPtr.size() - 1]->SetController(specs.controllerType);
				}
			}
			else
			{
				//temp
				parent->AddChild(specs);
			}
		}

		GameObj* GetObjType(GameObjType _objType)
		{
			for (int i = 0; i < vecObjRootsPtr.size(); i++)
			{
				if (vecObjRootsPtr[i]->IsObjType(_objType))
				{
					return vecObjRootsPtr[i];
				}
			}
			
			return nullptr;
		}
	};
}