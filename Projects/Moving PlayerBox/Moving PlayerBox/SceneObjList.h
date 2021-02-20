#pragma once
#include <vector>
#include "SceneObj.h"
#include <iostream>

namespace RB
{
	class SceneObjList
	{
	private:
		std::vector<SceneObj*> vecObjPtr;

	public:
		SceneObjList()
		{
			std::cout << "constructing SceneObjList" << std::endl;
		}

		~SceneObjList()
		{
			std::cout << "destructing SceneObjList" << std::endl;

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
			SceneObj* obj = new SceneObj(vecObjPtr.size());
			obj->SetName(_name);
			vecObjPtr.push_back(obj);
		}

		SceneObj* GetObj(int _id)
		{
			return vecObjPtr[_id];
		}
	};
}