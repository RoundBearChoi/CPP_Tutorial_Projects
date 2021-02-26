#pragma once
#include "GameSpriteType.h"
#include "DecalPath.h"

namespace RB
{
	class GameDecalPath : public DecalPath
	{
	public:
		int GetCount() override
		{
			return (int)GameSpriteType::COUNT;
		}

		std::string GetPath(int _index) override
		{
			GameSpriteType spriteType = (GameSpriteType)_index;

			if (spriteType == GameSpriteType::playerbox_green)
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
			else if (spriteType == GameSpriteType::shit_box32x32)
			{
				return "PNG files/shit_box32x32.png";
			}
			else if (spriteType == GameSpriteType::pixel_run_sheet)
			{
				return "PNG files/pixel_run_sheet.png";
			}
			else if (spriteType == GameSpriteType::idle_sheet)
			{
				return "PNG files/idle_sheet.png";
			}

			return "none";
		}
	};
}