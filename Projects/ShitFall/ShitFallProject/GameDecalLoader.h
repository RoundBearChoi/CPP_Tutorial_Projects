#pragma once
#include "olcPixelGameEngine.h"
#include "DecalLoader.h"
#include "SpritePath.h"

namespace RB
{
	class GameDecalLoader : public DecalLoader
	{
	public:
		GameDecalLoader()
		{
			std::cout << "constructing GameDecalLoader" << std::endl;

			LoadSprites();
			LoadDecals();
		}

		void LoadSprites() override
		{
			for (int i = 0; i < (int)GameSpriteType::COUNT; i++)
			{
				std::string path = SpritePath::GetPath((GameSpriteType)i);
				vecSpritePtr.push_back(new olc::Sprite(path));
				std::cout << "constructing Sprite: " << path << std::endl;
			}
		}
	};
}