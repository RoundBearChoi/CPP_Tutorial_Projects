#pragma once
#include <vector>
#include "SceneObj.h"

namespace RB
{
	class SceneObjList
	{
	private:
		std::vector<SceneObj> vecObjects;

	public:
		//void UpdateAll()
		//{
		//	for (int i = 0; i < vecObjects.size(); i++)
		//	{
		//		StateController* controller = vecObjects[i].GetController();
		//
		//		if (controller != nullptr)
		//		{
		//			controller->UU();
		//		}
		//	}
		//}

		void CreateObj(const std::string& _name)
		{
			SceneObj obj;
			obj.SetID(vecObjects.size());
			obj.SetName(_name);
			vecObjects.push_back(obj);
		}

		SceneObj* GetObj(int _id)
		{
			return &vecObjects[_id];
		}
	};
}