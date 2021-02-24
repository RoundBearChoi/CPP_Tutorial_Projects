#pragma once
#include "GameSpriteType.h"
#include "RenderOffsetType.h"

namespace RB
{
	class RenderPair
	{
		GameSpriteType spriteType = GameSpriteType::NONE;
		RenderOffsetType offsetType = RenderOffsetType::NONE;
	};
}