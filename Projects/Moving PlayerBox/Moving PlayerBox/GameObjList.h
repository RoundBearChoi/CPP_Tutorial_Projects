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

		void UpdateAll(float deltaTime, float xAxis)
		{
			for (int i = 0; i < vecObjPtr.size(); i++)
			{
				PlayerController* controller = vecObjPtr[i]->GetController();
				vecObjPtr[i]->updateData.elapsedTime = deltaTime;
				vecObjPtr[i]->updateData.inputXAxis = xAxis;

				if (controller != nullptr)
				{
					controller->Update(vecObjPtr[i]->updateData);
					controller->CheckNextTransition();
				}
			}
		}

		void CreateObj(const std::string& _name)
		{
			GameObj* obj = new GameObj(vecObjPtr.size());
			obj->SetName(_name);
			vecObjPtr.push_back(obj);
		}

		GameObj* GetObj(int _id)
		{
			return vecObjPtr[_id];
		}
	};
}