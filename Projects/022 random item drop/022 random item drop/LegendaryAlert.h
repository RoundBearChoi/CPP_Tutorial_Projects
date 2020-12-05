#pragma once
#include <Windows.h>
//#include <filesystem>

namespace Roundbeargames
{
	class LegendaryAlert
	{
	public:
		void Alert()
		{
			// using current_path to get starting file path..
			// (and putting .wav file in that location)
			// std::filesystem::path currentPath = std::filesystem::current_path();

			// Winmm.lib is required ("Additional Depencies" under Linker)
			// https://youtu.be/9WeDQHi6sJs
			bool played = PlaySound(
				TEXT("legendarydrop.wav"),
				NULL,
				SND_ASYNC);
		}
	};
}