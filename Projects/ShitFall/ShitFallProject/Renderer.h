#pragma once
#include "olcPixelGameEngine.h"
#include "ObjData.h"

namespace RB
{
	class Renderer
	{
	public:
		void Render(olc::PixelGameEngine* engine, olc::Decal* decal, const ObjData& data)
		{
			std::array<olc::vf2d, 4> points;

			if (data.offsetType == OffsetType::NONE)
			{
				points[0] = { data.position.x, data.position.y };
				points[1] = { data.position.x, data.position.y + data.objHeight };
				points[2] = { data.position.x + data.objWidth, data.position.y + data.objHeight };
				points[3] = { data.position.x + data.objWidth, data.position.y };
			}
			else if (data.offsetType == OffsetType::CENTER_CENTER)
			{
				olc::vf2d offset(0.0f, 0.0f);
				offset.x = -(data.objWidth / 2.0f);
				offset.y = -(data.objHeight / 2.0f);

				points[0] = { data.position.x - offset.x, data.position.y - offset.y };
				points[1] = { data.position.x - offset.x, data.position.y + offset.y };
				points[2] = { data.position.x + offset.x, data.position.y + offset.y };
				points[3] = { data.position.x + offset.x, data.position.y - offset.y };
			}
			else if (data.offsetType == OffsetType::BOTTOM_CENTER)
			{
				olc::vf2d offset(0.0f, 0.0f);
				offset.x = -(data.objWidth / 2.0f);

				points[0] = { data.position.x - offset.x, data.position.y - data.objHeight };
				points[1] = { data.position.x - offset.x, data.position.y };
				points[2] = { data.position.x + offset.x, data.position.y };
				points[3] = { data.position.x + offset.x, data.position.y - data.objHeight };
			}

			engine->DrawWarpedDecal(decal, points);
		}
	};
}