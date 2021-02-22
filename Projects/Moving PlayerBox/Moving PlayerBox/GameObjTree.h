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

		void CreateObj(int _typeIndex, int _controllerTypeIndex = 0, GameObj* parent = nullptr)
		{
			if (parent == nullptr)
			{
				vecObjPtr.push_back(new GameObj(_typeIndex));

				if (_controllerTypeIndex != 0)
				{
					vecObjPtr[vecObjPtr.size() - 1]->SetController(_controllerTypeIndex);
				}
			}
			else
			{
				//temp
				parent->AddChild(_typeIndex, _controllerTypeIndex);
			}
		}

		GameObj* GetObjType(int _typeIndex)
		{
			for (int i = 0; i < vecObjPtr.size(); i++)
			{
				if (vecObjPtr[i]->GetTypeID() == _typeIndex)
				{
					return vecObjPtr[i];
				}
			}
			
			return nullptr;
		}
	};
}