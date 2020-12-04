#pragma once
#include <vector>
#include <random>
#include <iostream>

namespace Roundbeargames
{
	class Shuffle
	{
    public:
		void Randomize(std::vector<int> &targetVector)
		{
            std::random_device device;
            std::mt19937 generator(device());

            std::shuffle(targetVector.begin(), targetVector.end(), generator);
		}
	};
}