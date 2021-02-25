#pragma once
#include <vector>
#include "olcPixelGameEngine.h"
#include "DecalPath.h"

namespace RB
{
	class DecalLoader
	{
	private:
		std::vector<olc::Sprite*> vecSpritePtr;
		std::vector<olc::Decal*> vecDecalPtr;

	public:
		DecalLoader()
		{
			std::cout << "constructing DecalLoader" << std::endl;
		}

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

		template<class T>
		void LoadSprites()
		{
			if (std::is_base_of<DecalPath, T>::value)
			{
				T pathGetter;

				for (int i = 0; i < pathGetter.GetCount(); i++)
				{
					std::string path = pathGetter.GetPath(i);
					vecSpritePtr.push_back(new olc::Sprite(path));
					std::cout << "constructing Sprite: " << path << std::endl;
				}
			}
		}

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