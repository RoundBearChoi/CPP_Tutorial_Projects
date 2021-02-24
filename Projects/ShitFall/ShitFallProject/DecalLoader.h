#pragma once
#include <vector>
#include "olcPixelGameEngine.h"

namespace RB
{
	class DecalLoader
	{
	protected:
		std::vector<olc::Sprite*> vecSpritePtr;
		std::vector<olc::Decal*> vecDecalPtr;

	public:
		~DecalLoader()
		{
			std::cout << "destructing DecalLoader" << std::endl;

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

		virtual void LoadSprites() = 0;
		
		void LoadDecals()
		{
			for (int i = 0; i < vecSpritePtr.size(); i++)
			{
				std::cout << "constructing Decal: " << i << std::endl;
				vecDecalPtr.push_back(new olc::Decal(vecSpritePtr[i]));
			}
		}

		olc::Decal* GetDecal(int _index)
		{
			return vecDecalPtr[_index];
		}
	};
}