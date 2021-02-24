#pragma once
#include <iostream>
#include "DecalLoader.h"
#include "TitleSpriteType.h"

namespace RB
{
	class TitleDecalLoader : public DecalLoader
	{
	public:
		TitleDecalLoader()
		{
			std::cout << "constructing TitleDecalLoader" << std::endl;

			LoadSprites();
			LoadDecals();
		}

		void LoadSprites() override
		{
			for (int i = 0; i < (int)TitleSpriteType::COUNT; i++)
			{
				std::string path = SpritePath::GetPath((TitleSpriteType)i);
				vecSpritePtr.push_back(new olc::Sprite(path));
				std::cout << "constructing Sprite: " << path << std::endl;
			}
		}
	};
}