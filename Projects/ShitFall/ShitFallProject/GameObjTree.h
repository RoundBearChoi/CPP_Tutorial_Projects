#pragma once
#include <vector>
#include "GameObj.h"
#include "ObjSpecs.h"
#include "DecalLoader.h"
#include "DevSettings.h"

namespace RB
{
	class GameObjTree
	{
	private:
		std::vector<GameObj*> vecAllObjs;
		std::vector<int> destructedObjIndex;
		size_t objsCreated = 0;

	public:
		GameObjTree()
		{
			IF_COUT{ std::cout << "constructing GameObjTree" << std::endl; }
			
		}

		~GameObjTree()
		{
			IF_COUT{ std::cout << "destructing GameObjTree" << std::endl; }

			for (int i = 0; i < vecAllObjs.size(); i++)
			{
				delete vecAllObjs[i];
			}
		}

		GameObj* ProcNewObj(const ObjSpecs& specs)
		{
			GameObj* newObj = new GameObj(specs);

			if (specs.controllerType != ControllerType::NONE)
			{
				newObj->SetController(specs.controllerType, specs.initialStateIndex);
			}

			vecAllObjs.push_back(newObj);
			SetID(newObj);

			return newObj;
		}

		void UpdateObjs(GameData& gameData)
		{
			for (int i = 0; i < vecAllObjs.size(); i++)
			{
				GameObj* obj = vecAllObjs[i];

				if (obj != nullptr)
				{
					//check collision against player
					if (obj->data.objType == GameObjType::individual_shit)
					{
						//only check on possible top collision
						if (obj->GetStateFrameCount() == 171 && !gameData.startSlowMo)
						{
							GameObj* player = GetObjType(GameObjType::player);

							if (obj->IsCollidingAgainst(player))
							{
								gameData.startSlowMo = true;
								obj->data.collided = true;

								player->ptrController->MakeTransition((int)PlayerStateType::DEAD);
							}
						}
					}

					ObjController* con = vecAllObjs[i]->ptrController;

					if (con != nullptr)
					{
						//update every obj
						con->UpdateObj(obj->data, gameData);

						//check child creation
						CreateObjFromQueue(obj);

						//check transition
						if (obj->data.nextStateIndex != 0)
						{
							con->MakeTransition(obj->data.nextStateIndex);
							obj->data.nextStateIndex = 0;
						}

						//delete obj
						if (con->DestructIsQueued())
						{
							delete vecAllObjs[i];
							vecAllObjs[i] = nullptr;
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

		void CreateObjFromQueue(GameObj* obj)
		{
			for (int i = 0; i < obj->data.GetCreationQueueCount(); i++)
			{
				ObjSpecs specs = obj->data.GetCreationSpecs(i);
				ProcNewObj(specs);
			}

			obj->data.ClearChildQueues();
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
					if (vecAllObjs[i]->data.debugDecalIndex != -1)
					{
						vecAllObjs[i]->Render(ptrEngine, decalLoader->GetDecal(vecAllObjs[i]->data.debugDecalIndex));
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
					if (vecAllObjs[i]->ptrController != nullptr)
					{
						AnimationData* data = vecAllObjs[i]->ptrController->GetStateRenderData();

						if (data != nullptr)
						{
							if (data->sourceSize.x > 0.0f && data->sourceSize.y > 0.0f)
							{
								RenderObjState(ptrEngine, decalLoader, vecAllObjs[i], data);
							}
						}
					}
				}
			}
		}

		void RenderObjState(olc::PixelGameEngine* ptrEngine, DecalLoader* decalLoader, GameObj* obj, AnimationData* aniData)
		{
			float x = obj->data.position.x;
			float y = obj->data.position.y;
			float width = obj->data.objWidth;
			float height = obj->data.objHeight;
			
			std::array<olc::vf2d, 4> points;

			if (obj->data.offsetType == OffsetType::BOTTOM_CENTER)
			{
				if (!aniData->reverseDecal)
				{
					points[0] = { x - width / 2.0f, y - height };
					points[1] = { x - width / 2.0f, y };
					points[2] = { x + width / 2.0f, y };
					points[3] = { x + width / 2.0f, y - height };
				}
				else
				{
					points[0] = { x + width / 2.0f, y - height };
					points[1] = { x + width / 2.0f, y };
					points[2] = { x - width / 2.0f, y };
					points[3] = { x - width / 2.0f, y - height };
				}
			}
			else if (obj->data.offsetType == OffsetType::CENTER_CENTER)
			{
				if (!aniData->reverseDecal)
				{
					points[0] = { x - width / 2.0f, y - height / 2.0f };
					points[1] = { x - width / 2.0f, y + height / 2.0f };
					points[2] = { x + width / 2.0f, y + height / 2.0f };
					points[3] = { x + width / 2.0f, y - height / 2.0f };
				}
				else
				{
					points[0] = { x + width / 2.0f, y - height / 2.0f };
					points[1] = { x + width / 2.0f, y + height / 2.0f };
					points[2] = { x - width / 2.0f, y + height / 2.0f };
					points[3] = { x - width / 2.0f, y - height / 2.0f };
				}
			}

			olc::Decal* d = decalLoader->GetDecal(aniData->decalIndex);
			ptrEngine->DrawPartialWarpedDecal(d, points, aniData->sourcePos, aniData->sourceSize);
		}
	};
}