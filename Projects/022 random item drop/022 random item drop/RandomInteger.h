#pragma once
#include <random>

namespace Roundbeargames
{
	// check out https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
	class RandomInteger
	{
	public:
		/// <summary>
		/// including min and max
		/// </summary>
		int GetInteger(int min, int max)
		{
			std::random_device device;
			std::mt19937 generator(device());
			std::uniform_int_distribution<int> distribution(min, max);

			return distribution(generator);
		}

		RandomInteger()
		{
			std::cout << "constructing randominteger.." << std::endl;
			std::cout << std::endl;
		}

		~RandomInteger()
		{
			std::cout << std::endl;
			std::cout << "destructing randominteger.." << std::endl;
		}
	};
}