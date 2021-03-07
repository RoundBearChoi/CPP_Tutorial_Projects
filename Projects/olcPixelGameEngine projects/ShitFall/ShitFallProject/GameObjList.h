#pragma once
#include <vector>
#include "GameObj.h"
#include "ObjSpecs.h"
#include "SlowMotion.h"
#include "SheetRenderer.h"

namespace RB
{
	class PlayerDeath;
	class ShitCenterSplash;

	class GameObjList
	{
	private:
		std::vector<GameObj*> vecAllObjs;
		std::vector<int> destructedObjIndex;
		size_t objsCreated = 0;
		SlowMotion slowMotion;
		SheetRenderer sheetRenderer;

		void CreateObjFromQueue(GameObj* obj)
		{
			std::vector<State*>& vecQueues = obj->ptrStateController->GetCreationQueues();
			std::vector<ObjSpecs>& vecSpecs = obj->ptrStateController->GetCreationSpecs();

			for (int i = 0; i < vecQueues.size(); i++)
			{
				if (vecSpecs.size() > i)
				{
					CreateObj(vecSpecs[i], vecQueues[i]);
				}
			}

			vecQueues.clear();
			vecSpecs.clear();
		}

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
			GameObj* obj = new GameObj(specs);

			//every obj has a state controller
			obj->ptrStateController = new StateController();
			obj->ptrStateController->CreateState<InitialState>();
						
			vecAllObjs.push_back(obj);
			SetID(obj);
		}

		void CreateObj(const ObjSpecs& specs, State* existingState)
		{
			GameObj* obj = new GameObj(specs);

			//every obj has a state controller
			obj->ptrStateController = new StateController();
			obj->ptrStateController->SetCurrentState(existingState);

			vecAllObjs.push_back(obj);
			SetID(obj);
		}

		void UpdateObjs(GameData& gameData)
		{
			slowMotion.UpdateSlowMoCounter();

			for (int i = 0; i < vecAllObjs.size(); i++)
			{
				if (vecAllObjs[i] == nullptr)
				{
					continue;
				}

				if (!slowMotion.SkipUpdate(vecAllObjs[i]->data.objTag))
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
			StateController* con = obj->ptrStateController;

			if (con != nullptr)
			{
				con->UpdateObj(obj->data, gameData);

				CreateObjFromQueue(obj);

				con->MakeStateTransition();
			}
		}

		bool DeleteObj(GameObj* obj)
		{
			StateController* con = obj->ptrStateController;

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
			if (obj->data.objTag == ObjTag::SHIT)
			{
				//only check on possible top collision
				if (obj->GetStateFrameCount() == 170)
				{
					GameObj* player = GetObj(ObjTag::PLAYER);

					if (!player->ptrStateController->CurrentStateIs<PlayerDeath>())
					{
						if (obj->IsCollidingAgainst(player))
						{
							player->ptrStateController->CreateState<PlayerDeath>();
							obj->ptrStateController->CreateState<ShitCenterSplash>();
						}
					}
				}
			}
		}

		GameObj* GetObj(int _index)
		{
			return vecAllObjs[_index];
		}

		GameObj* GetObj(ObjTag _tag)
		{
			for (int i = 0; i < vecAllObjs.size(); i++)
			{
				if (vecAllObjs[i]->data.objTag == _tag)
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

		void RenderStates(bool update, olc::PixelGameEngine* ptrEngine, DecalLoader* decalLoader)
		{
			for (int i = 0; i < vecAllObjs.size(); i++)
			{
				if (vecAllObjs[i] != nullptr)
				{
					sheetRenderer.Render(update, slowMotion.SkipUpdate(vecAllObjs[i]->data.objTag), ptrEngine, decalLoader, vecAllObjs[i]);
				}
			}
		}
	};
}