#pragma once
#include <cmath>
#include "AnimationData.h"

namespace RB
{
	class StateAnimation
	{
	private:
		//params
		int totalWidth = 0;
		int totalHeight = 0;
		int tileCountX = 0;
		int tileCountY = 0;
		int totalTiles = 0;

		//status
		int currentTile = 0;
		bool playOnce = false;
		AnimationData data;

		//next frame delay
		int transitionDelay = 0;
		int delayCount = 0;

	public:
		void SetParams(int _decalIndex, int _totalWith, int _totalHeight, int _tileCountX, int _tileCountY, int _totalTileCount, bool _reverse)
		{
			data.decalIndex = _decalIndex;
			data.reverseDecal = _reverse;

			totalWidth = _totalWith;
			totalHeight = _totalHeight;
			tileCountX = _tileCountX;
			tileCountY = _tileCountY;
			totalTiles = _totalTileCount;
		}

		AnimationData* GetRenderData(bool update, bool skipUpdate)
		{
			if (currentTile >= totalTiles)
			{
				if (playOnce)
				{
					currentTile = totalTiles - 1;
				}
				else
				{
					currentTile = 0;
				}
			}

			data.sourceSize.x = (float)totalWidth / (float)tileCountX;
			data.sourceSize.y = (float)totalHeight / (float)tileCountY;

			if (data.sourceSize.x != 0.0f && data.sourceSize.y > 0.0f)
			{
				data.sourcePos.x = (currentTile % tileCountX) * data.sourceSize.x;
				data.sourcePos.y = floorf((float)currentTile / (float)tileCountX) * data.sourceSize.y;
			}

			if (update && !skipUpdate)
			{
				delayCount++;

				if (delayCount >= transitionDelay)
				{
					delayCount = 0;
					currentTile++;
				}
			}

			return &data;
		}

		void SetDelayTime(int _delayTime)
		{
			transitionDelay = _delayTime;
		}

		void SetPlayOnce(bool _once)
		{
			playOnce = _once;
		}

		bool OnLastAnimationFrame()
		{
			if (currentTile == totalTiles - 1)
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