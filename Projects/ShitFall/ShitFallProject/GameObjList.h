#pragma once
#include <vector>
#include "GameObj.h"
#include "ObjSpecs.h"
#include "SlowMotion.h"
#include "SheetRenderer.h"
#include "PlayerDeath.h"

namespace RB
{
	class GameObjList
	{
	private:
		std::vector<GameObj*> vecAllObjs;
		std::vector<int> destructedObjIndex;
		size_t objsCreated = 0;
		SlowMotion slowMotion;
		SheetRenderer sheetRenderer;

	public:
		GameObjList()
		{
			IF_COUT{ std::cout << "constructing GameObjTree" << std::endl; }
			
		}

		~GameObjList()
		{
			IF_COUT{ std::cout << "destructing GameObjTree" << std::endl; }

			for (int i = 0; i < vecAllObjs.size(); i++)
			{
				delete vecAllObjs[i];
			}
		}

		template<class InitialState>
		void CreateObj(const ObjSpecs& specs)
		{
			GameObj* newObj = new GameObj(specs);

			//every obj has a state controller
			newObj->ptrController = new StateController();
			newObj->ptrController->CreateState<InitialState>(newObj->data);

			vecAllObjs.push_back(newObj);
			SetID(newObj);
		}

		void UpdateObjs(GameData& gameData)
		{
			slowMotion.UpdateSlowMoCounter();

			for (int i = 0; i < vecAllObjs.size(); i++)
			{
				if (!slowMotion.SkipUpdate(vecAllObjs[i]->data.objType))
				{
					GameObj* obj = vecAllObjs[i];

					if (obj != nullptr)
					{
						UpdateOnPlayerCollision(obj);
						UpdateState(obj, i, gameData);
						slowMotion.AddSlowMo(obj);

						if (DeleteObj(obj))
						{
							delete vecAllObjs[i];
							vecAllObjs[i] = nullptr;
							destructedObjIndex.push_back(i);
						}
					}
				}
			}

			//remove deleted obj pointers
			for (int i = 0; i < destructedObjIndex.size(); i++)
			{
				vecAllObjs.erase(vecAllObjs.begin() + destructedObjIndex[i]);
			}

			destructedObjIndex.clear();
		}

		void UpdateState(GameObj* obj, int objIndex, GameData& gameData)
		{
			StateController* con = obj->ptrController;

			if (con != nullptr)
			{
				con->UpdateObj(obj->data, gameData);

				//CreateObjFromQueue(obj);

				//check transition
				con->MakeStateTransition();

				//if ( data.nextStateIndex != 0)
				//{
				//	con->MakeTransition(obj->data, obj->data.nextStateIndex);
				//	obj->data.nextStateIndex = 0;
				//}
			}
		}

		bool DeleteObj(GameObj* obj)
		{
			StateController* con = obj->ptrController;

			if (con != nullptr)
			{
				if (con->DeleteObj())
				{
					return true;
				}
			}
			
			return false;
		}

		void UpdateOnPlayerCollision(GameObj* obj)
		{
			if (obj->data.objType == GameObjType::individual_shit)
			{
				//only check on possible top collision
				if (obj->GetStateFrameCount() == 171)
				{
					GameObj* player = GetObjType(GameObjType::player);

					if (obj->IsCollidingAgainst(player))
					{
						obj->data.collided = true;

						//if (player->ptrController->GetCurrentStateIndex() != (int)PlayerStateType::DEAD)
						//{
						//	player->ptrController->MakeTransition<PlayerDeath>(obj->data, (int)PlayerStateType::DEAD);
						//}
					}
				}
			}
		}

		//void CreateObjFromQueue(GameObj* obj)
		//{
		//	for (int i = 0; i < obj->data.GetCreationQueueCount(); i++)
		//	{
		//		ObjSpecs specs = obj->data.GetCreationSpecs(i);
		//		CreateObj(specs);
		//	}
		//
		//	obj->data.ClearChildQueues();
		//}

		GameObj* GetObj(int _index)
		{
			return vecAllObjs[_index];
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

		void RenderObjs(olc::PixelGameEngine* ptrEngine, DecalLoader* decalLoader)
		{
			for (int i = 0; i < vecAllObjs.size(); i++)
			{
				if (vecAllObjs[i] != nullptr)
				{
					if (vecAllObjs[i]->data.decalIndex != -1)
					{
						vecAllObjs[i]->Render(ptrEngine, decalLoader->GetDecal(vecAllObjs[i]->data.decalIndex));
					}
				}
			}
		}

		void RenderStates(olc::PixelGameEngine* ptrEngine, DecalLoader* decalLoader)
		{
			for (int i = 0; i < vecAllObjs.size(); i++)
			{
				if (vecAllObjs[i] != nullptr)
				{
					sheetRenderer.Render(ptrEngine, decalLoader, vecAllObjs[i]);
				}
			}
		}
	};
}