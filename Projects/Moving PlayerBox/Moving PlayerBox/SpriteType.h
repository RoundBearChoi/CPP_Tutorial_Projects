#pragma once
#include <iostream>

namespace RB
{
	enum class GameSpriteType
	{
		diamond_red = 0,
		playerbox_green,
		background,

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

			return "none";
		}
	};
}