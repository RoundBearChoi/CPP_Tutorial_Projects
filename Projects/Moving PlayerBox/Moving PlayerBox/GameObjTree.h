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
		std::vector<int> destructedObjIndex;
		size_t objsCreated = 0;
		int nextSceneQueue = 0;

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

				if (obj != nullptr)
				{
					ObjController* controller = vecAllObjs[i]->GetController();

					if (controller != nullptr)
					{
						//update every obj
						controller->UpdateObj(obj->data, gameData);

						//check child creation
						CreateChildren(obj);

						//delete obj
						if (controller->DestructIsQueued())
						{
							//remove pointer from vec
							obj->GetParent()->ClearDestructableChildren();

							delete vecAllObjs[i];
							vecAllObjs[i] = nullptr;
						}
						else
						{
							//check transition
							int nextState = obj->GetController()->NextStateIndex();

							if (nextState != 0)
							{
								controller->MakeTransition(nextState);
							}
						}
					}
				}
				else
				{
					destructedObjIndex.push_back(i);
				}
			}

			//remove deleted obj pointers
			for (int i = 0; i < destructedObjIndex.size(); i++)
			{
				vecAllObjs.erase(vecAllObjs.begin() + destructedObjIndex[i]);
			}

			destructedObjIndex.clear();
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

				obj->AddToHierarchy(child);
				vecAllObjs.push_back(child);
				SetID(child);
			}

			obj->data.ClearChildQueues();
		}

		void CreateObj(ObjSpecs specs)
		{
			GameObj* newObj = new GameObj(specs);
			vecAllObjs.push_back(newObj);

			if (specs.controllerType != ControllerType::NONE)
			{
				newObj->SetController(specs.controllerType);
			}

			SetID(newObj);
		}

		GameObj* GetObjType(GameObjType _objType)
		{
			for (int i = 0; i < vecAllObjs.size(); i++)
			{
				if (vecAllObjs[i]->data.objType == _objType)
				{
					return vecAllObjs[i];
				}
			}
			
			return nullptr;
		}

		void SetID(GameObj* obj)
		{
			if (objsCreated == (size_t) -1)
			{
				objsCreated = 0;
			}

			obj->data.SetCreationID(objsCreated);
			objsCreated++;
		}

		int GetNextSceneQueue()
		{
			for (int i = 0; i < vecAllObjs.size(); i++)
			{
				if (vecAllObjs[i] != nullptr)
				{
					ObjController* controller = vecAllObjs[i]->GetController();

					if (controller != nullptr)
					{
						nextSceneQueue = vecAllObjs[i]->GetController()->NextSceneIndex();

						if (nextSceneQueue != 0)
						{
							return nextSceneQueue;
						}
					}
				}
			}

			return 0;
		}
	};
}