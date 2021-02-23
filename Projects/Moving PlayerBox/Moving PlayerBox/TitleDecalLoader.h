#pragma once
#include <iostream>
#include "DecalLoader.h"

namespace RB
{
	class TitleDecalLoader : public DecalLoader
	{
		TitleDecalLoader()
		{
			std::cout << "constructing TitleDecalLoader" << std::endl;

			LoadSprites();
			LoadDecals();
		}

		void LoadSprites() override
		{
			//for (int i = 0; i < (int)GameSpriteType::COUNT; i++)
			//{
			//	std::string path = SpritePath::GetPath((GameSpriteType)i);
			//	vecSpritePtr.push_back(new olc::Sprite(path));
			//	std::cout << "constructing Sprite: " << path << std::endl;
			//}
		}
	};
}