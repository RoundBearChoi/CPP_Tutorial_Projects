#pragma once
#include "olcPixelGameEngine.h"
#include "ObjData.h"

namespace RB
{
	class Renderer
	{
	private:
		ObjData* data = nullptr;

	public:
		void SetObjData(ObjData* ptrData)
		{
			data = ptrData;
		}

		void Render(olc::PixelGameEngine* engine, olc::Decal* decal)
		{
			std::array<olc::vf2d, 4> points;

			if (data->offsetType == OffsetType::NONE)
			{
				points[0] = { data->position.x, data->position.y };
				points[1] = { data->position.x, data->position.y + data->size.y };
				points[2] = { data->position.x + data->size.x, data->position.y + data->size.y };
				points[3] = { data->position.x + data->size.x, data->position.y };
			}
			else if (data->offsetType == OffsetType::CENTER_CENTER)
			{
				olc::vf2d offset(0.0f, 0.0f);
				offset.x = -(data->size.x / 2.0f);
				offset.y = -(data->size.y / 2.0f);

				points[0] = { data->position.x - offset.x, data->position.y - offset.y };
				points[1] = { data->position.x - offset.x, data->position.y + offset.y };
				points[2] = { data->position.x + offset.x, data->position.y + offset.y };
				points[3] = { data->position.x + offset.x, data->position.y - offset.y };
			}
			else if (data->offsetType == OffsetType::BOTTOM_CENTER)
			{
				olc::vf2d offset(0.0f, 0.0f);
				offset.x = -(data->size.x / 2.0f);

				points[0] = { data->position.x - offset.x, data->position.y - data->size.y };
				points[1] = { data->position.x - offset.x, data->position.y };
				points[2] = { data->position.x + offset.x, data->position.y };
				points[3] = { data->position.x + offset.x, data->position.y - data->size.y };
			}

			engine->DrawWarpedDecal(decal, points);
		}
	};
}