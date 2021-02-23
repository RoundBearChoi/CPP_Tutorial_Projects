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

		~GameDecalLoader() override
		{
			std::cout << "destructing GameDecalLoader" << std::endl;

			for (int i = 0; i < vecSpritePtr.size(); i++)
			{
				std::cout << "destructing Sprite: " << i << std::endl;
				delete vecSpritePtr[i];
			}

			for (int i = 0; i < vecDecalPtr.size(); i++)
			{
				std::cout << "destructing Decal: " << i << std::endl;
				delete vecDecalPtr[i];
			}
		}

		void LoadSprites()
		{
			for (int i = 0; i < (int)GameSpriteType::COUNT; i++)
			{
				std::string path = SpritePath::GetPath((GameSpriteType)i);
				vecSpritePtr.push_back(new olc::Sprite(path));
				std::cout << "constructing Sprite: " << path << std::endl;
			}
		}

		void LoadDecals() override
		{
			for (int i = 0; i < vecSpritePtr.size(); i++)
			{
				std::cout << "constructing Decal: " << i << std::endl;
				vecDecalPtr.push_back(new olc::Decal(vecSpritePtr[i]));
			}
		}
	};
}