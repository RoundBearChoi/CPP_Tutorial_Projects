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

			switch (spriteType)
			{
			case GameSpriteType::playerbox_green: return "PNG files/playerbox_green.png";
			case GameSpriteType::background: return "PNG files/background.png";
			case GameSpriteType::redbox_10x10: return "PNG files/redbox_10x10.png";
			case GameSpriteType::shit_box32x32: return "PNG files/shit_box32x32.png";
			case GameSpriteType::pixel_run_sheet: return "PNG files/pixel_run_sheet.png";
			case GameSpriteType::idle_sheet: return "PNG files/idle_sheet.png";
			case GameSpriteType::y_or_n460x330: return "PNG files/y_or_n460x330.png";
			case GameSpriteType::shit_restart: return "PNG files/shitrestart.png";
			case GameSpriteType::shit: return "PNG files/shit.png";
			case GameSpriteType::ko_sheet_2: return "PNG files/ko_sheet_2.png";
			case GameSpriteType::upsplash_sheet_3: return "PNG files/upsplash_sheet_3.png";
			case GameSpriteType::centersplash_sheet: return "PNG files/centersplash_sheet.png";
			}

			return "none";
		}
	};
}