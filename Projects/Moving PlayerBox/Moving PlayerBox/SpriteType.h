#pragma once
#include <iostream>

namespace RB
{
	enum class GameSpriteType
	{
		diamond_red,
		playerbox_green,
		background,
		redbox_10x10,

		COUNT,
	};

	class SpriteType
	{
	public:
		static std::string GetStringPath(GameSpriteType spriteType)
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