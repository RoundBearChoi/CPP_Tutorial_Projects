#pragma once
#include <vector>
#include "GameObj.h"
#include <iostream>

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
					controller->UpdateObj(vecObjPtr[i]->position, gameData);
					controller->CheckNextTransition();
				}
			}
		}

		void CreateObj(int _typeID)
		{
			GameObj* obj = new GameObj(_typeID);
			vecObjPtr.push_back(obj);
		}

		GameObj* GetObjType(int _typeID)
		{
			for (int i = 0; i < vecObjPtr.size(); i++)
			{
				if (vecObjPtr[i]->GetTypeID() == _typeID)
				{
					return vecObjPtr[_typeID];
				}
			}
			
			return nullptr;
		}
	};
}