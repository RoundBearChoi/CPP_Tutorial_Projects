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

			if (spriteType == TitleSpriteType::background)
			{
				return "PNG files/background.png";
			}
			else if (spriteType == TitleSpriteType::title_line500x180)
			{
				return "PNG files/title_line500x180.png";
			}
			else if (spriteType == TitleSpriteType::playerbox_green)
			{
				return "PNG files/playerbox_green.png";
			}
			else if (spriteType == TitleSpriteType::press_enter300x90)
			{
				return "PNG files/press_enter300x90.png";
			}
			else if (spriteType == TitleSpriteType::shitfall_title)
			{
				return "PNG files/shitfall_title.png";
			}
			return "none";
		}
	};
}