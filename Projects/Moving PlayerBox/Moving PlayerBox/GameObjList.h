#pragma once
#include <vector>
#include "GameObj.h"
#include <iostream>

namespace RB
{
	class GameObjList
	{
	private:
		std::vector<GameObj*> vecObjPtr;

	public:
		GameObjList()
		{
			std::cout << "constructing GameObjList" << std::endl;
		}

		~GameObjList()
		{
			std::cout << "destructing GameObjList" << std::endl;

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

		void CreateObj(int _id)
		{
			GameObj* obj = new GameObj(_id);
			vecObjPtr.push_back(obj);
		}

		GameObj* GetObj(int _id)
		{
			return vecObjPtr[_id];
		}
	};
}