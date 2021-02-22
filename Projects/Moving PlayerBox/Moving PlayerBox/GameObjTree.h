#pragma once
#include <vector>
#include <iostream>
#include "GameObj.h"
#include "GameObjType.h"

namespace RB
{
	class GameObjTree
	{
	private:
		std::vector<GameObj*> vecObjPtr;

	public:
		GameObjTree()
		{
			std::cout << "constructing GameObjTree" << std::endl;
		}

		~GameObjTree()
		{
			std::cout << "destructing GameObjTree" << std::endl;

			for (int i = 0; i < vecObjPtr.size(); i++)
			{
				delete vecObjPtr[i];
			}
		}

		void UpdateAll(const GameData& gameData)
		{
			for (int i = 0; i < vecObjPtr.size(); i++)
			{
				ObjController* controller = vecObjPtr[i]->GetController();

				if (controller != nullptr)
				{
					controller->UpdateObj(vecObjPtr[i]->data, gameData);
					
					int nextState = vecObjPtr[i]->GetController()->NextStateIndex();

					if (nextState != 0)
					{
						controller->MakeTransition(nextState);
					}
					
					//add child from info
					int Queues = vecObjPtr[i]->data.GetChildQueues();

					for (int child = 0; child < Queues; child++)
					{
						vecObjPtr[i]->data.RemoveQueue();
					}
				}
			}
		}

		void CreateObj(GameObjType _objType, ControllerType _controllerType = ControllerType::NONE, GameObj* parent = nullptr)
		{
			if (parent == nullptr)
			{
				vecObjPtr.push_back(new GameObj(_objType));

				if (_controllerType != ControllerType::NONE)
				{
					vecObjPtr[vecObjPtr.size() - 1]->SetController(_controllerType);
				}
			}
			else
			{
				//temp
				parent->AddChild(_objType, _controllerType);
			}
		}

		GameObj* GetObjType(GameObjType _objType)
		{
			for (int i = 0; i < vecObjPtr.size(); i++)
			{
				if (vecObjPtr[i]->IsObjType(_objType))
				{
					return vecObjPtr[i];
				}
			}
			
			return nullptr;
		}
	};
}