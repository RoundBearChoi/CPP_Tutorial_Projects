#pragma once
#include "AnimationData.h"

class SpriteAnimation
{
private:
	float mInterval = 0.0f;
	int mTotalWidth = 0;
	int mTotalHeight = 0;
	int mTileCountX = 0;

	float mCurrentTime = 0.0f;
	int mCurrentTileX = 0;

public:
	void SetParams(float interval, int totalWith, int totalHeight, int tileCountX)
	{
		mInterval = interval;
		mTotalWidth = totalWith;
		mTotalHeight = totalHeight;
		mTileCountX = tileCountX;
	}

	AnimationData GetInfo(float fElapsedTime)
	{
		mCurrentTime += fElapsedTime;

		if (mCurrentTime >= mInterval)
		{
			mCurrentTime = 0.0f;
			mCurrentTileX++;
		}

		if (mCurrentTileX >= mTileCountX)
		{
			mCurrentTileX = 0;
		}

		AnimationData data;

		data.sourcePos.x = mCurrentTileX * (mTotalWidth / mTileCountX);
		data.sourcePos.y = 0.0f;
		data.sourceSize.x = mTotalWidth / mTileCountX;
		data.sourceSize.y = mTotalHeight;

		return data;
	}
};