#include <iostream>

void GetAceCombinations(int nAces)
{
	std::cout << "you have " << nAces << std::endl;

	for (int total = 0; total <= nAces; total++)
	{
		int result = 0;

		for (int elevens = 0; elevens < total; elevens++)
		{
			std::cout << "11 ";
			result += 11;
		}

		for (int ones = 0; ones < nAces - total; ones++)
		{
			std::cout << "1 ";
			result += 1;
		}

		std::cout << " - result: " << result << std::endl;
	}

	std::cout << std::endl;
}

int main()
{
	GetAceCombinations(4);
	GetAceCombinations(3);
	GetAceCombinations(2);
	GetAceCombinations(1);
}