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

		GameObj* ProcNewObj(ObjSpecs specs)
		{
			GameObj* newObj = new GameObj(specs);
			newObj->data.objWidth = specs.width;
			newObj->data.objHeight = specs.height;

			if (specs.controllerType != ControllerType::NONE)
			{
				newObj->SetController(specs.controllerType);
			}

			vecAllObjs.push_back(newObj);
			SetID(newObj);

			return newObj;
		}

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

		void UpdateAll(GameData& gameData)
		{
			for (int i = 0; i < vecAllObjs.size(); i++)
			{
				GameObj* obj = vecAllObjs[i];

				if (obj != nullptr)
				{
					//check collision against player
					if (obj->data.objType == GameObjType::individual_shit)
					{
						if (obj->GetStateFrameCount() == 171 && !gameData.startSlowMo)
						{
							if (obj->IsCollidingAgainst(GetObjType(GameObjType::player)))
							{
								gameData.startSlowMo = true;
								obj->data.collided = true;
							}
						}
					}

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
							int nextState = obj->GetController()->GetNextStateIndex();

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

				GameObj* child = ProcNewObj(specs);

				obj->AddToHierarchy(child);
			}

			obj->data.ClearChildQueues();
		}

		void CreateObj(ObjSpecs specs)
		{
			ProcNewObj(specs);
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

		int GetNextScene()
		{
			for (int i = 0; i < vecAllObjs.size(); i++)
			{
				if (vecAllObjs[i] != nullptr)
				{
					ObjController* controller = vecAllObjs[i]->GetController();

					if (controller != nullptr)
					{
						int nextScene = vecAllObjs[i]->GetController()->GetNextScene();

						if (nextScene != 0)
						{
							return nextScene;
						}
					}
				}
			}

			return 0;
		}
	};
}