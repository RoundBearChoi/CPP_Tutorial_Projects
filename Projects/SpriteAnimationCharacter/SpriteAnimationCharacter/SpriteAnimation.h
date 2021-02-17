#pragma once
#include "AnimationData.h"
#include <cmath>

class SpriteAnimation
{
private:
	float mInterval = 0.0f;
	int mTotalWidth = 0;
	int mTotalHeight = 0;
	int mTileCountX = 0;
	int mTileCountY = 0;
	int mTotalTileCount = 0;

	float mCurrentTime = 0.0f;
	int mCurrentTile = 0;

public:
	void SetParams(float interval, int totalWith, int totalHeight, int tileCountX, int tileCountY, int totalTiles)
	{
		mInterval = interval;
		mTotalWidth = totalWith;
		mTotalHeight = totalHeight;
		mTileCountX = tileCountX;
		mTileCountY = tileCountY;
		mTotalTileCount = totalTiles;
	}

	AnimationData GetInfo(float fElapsedTime)
	{
		mCurrentTime += fElapsedTime;

		if (mCurrentTime >= mInterval)
		{
			mCurrentTime = 0.0f;
			mCurrentTile++;
		}

		if (mCurrentTile >= mTotalTileCount)
		{
			mCurrentTile = 0;
		}

		AnimationData data;

		data.sourceSize.x = mTotalWidth / mTileCountX;
		data.sourceSize.y = mTotalHeight / mTileCountY;

		data.sourcePos.x = (mCurrentTile % mTileCountX) * data.sourceSize.x;
		data.sourcePos.y = floorf(mCurrentTile / mTileCountX) * data.sourceSize.y;

		return data;
	}
};