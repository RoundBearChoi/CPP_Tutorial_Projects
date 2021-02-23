#pragma once
#include <iostream>
#include "GameSpriteType.h"

namespace RB
{
	class SpritePath
	{
	public:
		static std::string GetPath(GameSpriteType spriteType)
		{
			if (spriteType == GameSpriteType::diamond_red)
			{
				return "PNG files/diamond_red.png";
			}
			else if (spriteType == GameSpriteType::playerbox_green)
			{
				return "PNG files/playerbox_green.png";
			}
			else if (spriteType == GameSpriteType::background)
			{
				return "PNG files/background.png";
			}
			else if (spriteType == GameSpriteType::redbox_10x10)
			{
				return "PNG files/redbox_10x10.png";
			}

			return "none";
		}
	};
}