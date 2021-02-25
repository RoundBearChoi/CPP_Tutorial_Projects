#pragma once
#include <cmath>
#include "AnimationData.h"

namespace RB
{
	class StateAnimation
	{
	private:
		int decalIndex = 0;
		int totalWidth = 0;
		int totalHeight = 0;
		int tileCountX = 0;
		int tileCountY = 0;

		int currentTile = 0;

	public:
		void SetParams(int _decalIndex, int _totalWith, int _totalHeight, int _tileCountX, int _tileCountY)
		{
			decalIndex = _decalIndex;
			totalWidth = _totalWith;
			totalHeight = _totalHeight;
			tileCountX = _tileCountX;
			tileCountY = _tileCountY;
		}

		AnimationData GetRenderData()
		{
			AnimationData data;

			data.sourceSize.x = (float)totalWidth / (float)tileCountX;
			data.sourceSize.y = (float)totalHeight / (float)tileCountY;

			data.sourcePos.x = (currentTile % tileCountX) * data.sourceSize.x;
			data.sourcePos.y = floorf((float)currentTile / (float)currentTile) * data.sourceSize.y;

			currentTile++;

			return data;
		}
	};
}