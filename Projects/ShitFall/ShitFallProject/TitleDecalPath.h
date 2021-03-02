#pragma once
#include "TitleSpriteType.h"
#include "DecalPath.h"

namespace RB
{
	class TitleDecalPath : public DecalPath
	{
	public:
		int GetCount() override
		{
			return (int)TitleSpriteType::COUNT;
		}

		std::string GetPath(int _index) override
		{
			TitleSpriteType spriteType = (TitleSpriteType)_index;

			switch (spriteType)
			{
			case TitleSpriteType::background: return "PNG files/background.png";
			case TitleSpriteType::title_line500x180: return "PNG files/title_line500x180.png";
			case TitleSpriteType::playerbox_green: return "PNG files/playerbox_green.png";
			case TitleSpriteType::press_enter300x90: return "PNG files/press_enter300x90.png";
			case TitleSpriteType::shitfall_title: return "PNG files/shitfall_title.png";
			case TitleSpriteType::pressenter: return "PNG files/pressenter.png";
			case TitleSpriteType::idle_sheet: return "PNG files/idle_sheet.png";
			}

			return "none";
		}
	};
}