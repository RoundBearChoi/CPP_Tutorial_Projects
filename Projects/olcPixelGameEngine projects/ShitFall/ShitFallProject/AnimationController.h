#pragma once
#include <cmath>
#include "AnimationData.h"

namespace RB
{
	class AnimationController
	{
	private:
		//params
		int totalWidth = 0;
		int totalHeight = 0;
		int tileCountX = 0;
		int tileCountY = 0;
		int totalTiles = 0;

	public:
		AnimationData data;

		void SetParams(int _decalTypeIndex, int _totalWith, int _totalHeight, int _tileCountX, int _tileCountY, int _totalTileCount, bool _reverse)
		{
			data.decalTypeIndex = _decalTypeIndex;
			data.reverseDecal = _reverse;

			totalWidth = _totalWith;
			totalHeight = _totalHeight;
			tileCountX = _tileCountX;
			tileCountY = _tileCountY;
			totalTiles = _totalTileCount;
		}

		AnimationData* GetRenderData(bool update, bool skipUpdate)
		{
			if (data.currentTile >= totalTiles)
			{
				if (data.playOnce)
				{
					data.currentTile = totalTiles - 1;
				}
				else
				{
					data.currentTile = 0;
				}
			}

			data.sourceSize.x = (float)totalWidth / (float)tileCountX;
			data.sourceSize.y = (float)totalHeight / (float)tileCountY;

			if (data.sourceSize.x != 0.0f && data.sourceSize.y > 0.0f)
			{
				data.sourcePos.x = (data.currentTile % tileCountX) * data.sourceSize.x;
				data.sourcePos.y = floorf((float)data.currentTile / (float)tileCountX) * data.sourceSize.y;
			}

			if (update && !skipUpdate)
			{
				data.delayCount++;

				if (data.delayCount >= data.transitionDelay)
				{
					data.delayCount = 0;
					data.currentTile++;
				}
			}

			return &data;
		}

		bool OnLastAnimationFrame()
		{
			if (data.currentTile == totalTiles - 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	};
}