#pragma once
#include "olcPixelGameEngine.h"
#include "DecalLoader.h"
#include "GameObj.h"
#include "AnimationData.h"

namespace RB
{
	class SheetRenderer
	{
	public:
		void Render(bool update, bool skipUpdate, olc::PixelGameEngine* ptrEngine, DecalLoader* decalLoader, GameObj* obj)
		{
			if (obj->ptrStateController != nullptr)
			{
				AnimationData* data = obj->ptrStateController->currentState->animationController.GetRenderData(update, skipUpdate);

				if (data != nullptr)
				{
					if (data->sourceSize.x > 0.0f && data->sourceSize.y > 0.0f)
					{
						RenderOnOffset(ptrEngine, decalLoader, obj, data);
					}
				}
			}
		}

		void RenderOnOffset(olc::PixelGameEngine* ptrEngine, DecalLoader* decalLoader, GameObj* obj, AnimationData* aniData)
		{
			float x = obj->data.position.x;
			float y = obj->data.position.y;
			float width = obj->data.size.x;
			float height = obj->data.size.y;

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

			olc::Decal* d = decalLoader->GetDecal(aniData->decalTypeIndex);
			ptrEngine->DrawPartialWarpedDecal(d, points, aniData->sourcePos, aniData->sourceSize);
		}
	};
}