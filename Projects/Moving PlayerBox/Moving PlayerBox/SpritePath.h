#pragma once
#include <iostream>

namespace RB
{
	enum class SpriteType
	{
		diamond_red,
		playerbox_green,
		background,
		redbox_10x10,

		COUNT,
	};

	class SpritePath
	{
	public:
		static std::string GetPath(SpriteType spriteType)
		{
			if (spriteType == SpriteType::diamond_red)
			{
				return "PNG files/diamond_red.png";
			}
			else if (spriteType == SpriteType::playerbox_green)
			{
				return "PNG files/playerbox_green.png";
			}
			else if (spriteType == SpriteType::background)
			{
				return "PNG files/background.png";
			}
			else if (spriteType == SpriteType::redbox_10x10)
			{
				return "PNG files/redbox_10x10.png";
			}

			return "none";
		}
	};
}