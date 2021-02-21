#pragma once
#include <vector>
#include "olcPixelGameEngine.h"

namespace RB
{
	class DecalLoader
	{
	protected:
		std::vector<olc::Sprite*> vecSpritePtr;
		std::vector<olc::Decal*> vecDecalPtr;

	public:
		virtual ~DecalLoader()
		{

		}

		virtual void LoadSprites() = 0;
		virtual void LoadDecals() = 0;

		olc::Decal* GetDecal(int _index)
		{
			return vecDecalPtr[_index];
		}
	};
}