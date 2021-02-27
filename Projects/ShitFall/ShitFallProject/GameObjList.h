#pragma once
#include <vector>
#include "GameObj.h"
#include "ObjSpecs.h"
#include "DecalLoader.h"
#include "DevSettings.h"
#include "SlowUpdate.h"

namespace RB
{
	class GameObjList
	{
	private:
		std::vector<GameObj*> vecAllObjs;
		std::vector<SlowUpdate> vecSlowUpdates;
		std::vector<int> destructedObjIndex;
		size_t objsCreated = 0;

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

		void CreateObj(const ObjSpecs& specs)
		{
			GameObj* newObj = new GameObj(specs);

			if (specs.controllerType != ControllerType::NONE)
			{
				newObj->SetController(specs.controllerType, specs.initialStateIndex);
			}

			vecAllObjs.push_back(newObj);
			SetID(newObj);
		}

		void UpdateObjs(GameData& gameData)
		{
			for (int i = 0; i < vecSlowUpdates.size(); i++)
			{
				vecSlowUpdates[i].UpdateSlowMoCounter();
			}

			for (int i = 0; i < vecAllObjs.size(); i++)
			{
				if (!SkipUpdate(vecAllObjs[i]->data.objType))
				{
					GameObj* obj = vecAllObjs[i];

					if (obj != nullptr)
					{
						UpdateOnPlayerCollision(obj);

						UpdateController(obj, i, gameData);

						if (DeleteObj(obj))
						{
							delete vecAllObjs[i];
							vecAllObjs[i] = nullptr;
							destructedObjIndex.push_back(i);
						}

						ProcSlowMo(vecAllObjs[i]);
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

		void UpdateController(GameObj* obj, int objIndex, GameData& gameData)
		{
			ObjController* con = obj->ptrController;

			if (con != nullptr)
			{
				con->UpdateObj(obj->data, gameData);

				CreateObjFromQueue(obj);

				//check transition
				if (obj->data.nextStateIndex != 0)
				{
					con->MakeTransition(obj->data.nextStateIndex, obj->data);
					obj->data.nextStateIndex = 0;
				}
			}
		}

		bool DeleteObj(GameObj* obj)
		{
			ObjController* con = obj->ptrController;

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

						if (player->ptrController->GetCurrentStateIndex() != (int)PlayerStateType::DEAD)
						{
							player->ptrController->MakeTransition((int)PlayerStateType::DEAD, obj->data);
						}
					}
				}
			}
		}

		bool SkipUpdate(GameObjType _targetType)
		{
			if (vecSlowUpdates.size() == 0)
			{
				return false;
			}
			
			for (int i = 0; i < vecSlowUpdates.size(); i++)
			{
				if (!vecSlowUpdates[i].CanUpdate())
				{
					if (_targetType == vecSlowUpdates[i].GetTargetType())
					{
						return true;
					}
				}
			}

			return false;
		}

		void ProcSlowMo(GameObj* obj)
		{
			if (obj != nullptr)
			{
				for (int messageIndex = 0; messageIndex < obj->data.GetSlowMoMessageCount(); messageIndex++)
				{
					SlowUpdateMessage message = obj->data.GetSlowMoMessage(messageIndex);

					if (vecSlowUpdates.size() > 0)
					{
						bool sameTargetFound = false;

						for (int sIndex = 0; sIndex < vecSlowUpdates.size(); sIndex++)
						{
							if (vecSlowUpdates[sIndex].GetTargetType() == message.targetType)
							{
								vecSlowUpdates[sIndex].SetDelayTime(message.targetFrameDelay);
								sameTargetFound = true;
							}
						}

						if (!sameTargetFound)
						{
							SlowUpdate slowUpdate(message.targetType, message.targetFrameDelay);
							vecSlowUpdates.push_back(slowUpdate);
						}
					}
					else
					{
						SlowUpdate slowUpdate(message.targetType, message.targetFrameDelay);
						vecSlowUpdates.push_back(slowUpdate);
					}
				}

				obj->data.ClearSlowMoMessages();
			}
		}

		void CreateObjFromQueue(GameObj* obj)
		{
			for (int i = 0; i < obj->data.GetCreationQueueCount(); i++)
			{
				ObjSpecs specs = obj->data.GetCreationSpecs(i);
				CreateObj(specs);
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