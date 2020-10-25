#include <iostream>

int main()
{
	std::string yourString;

	while (yourString[0] != 'q')
	{
		std::cout << "say something: ";
		std::cin >> yourString;

		std::cout << std::endl;
		std::cout << "you said: " << yourString << std::endl;
		std::cout << "first letter: " << yourString[0] << std::endl;

		std::cin.clear(); // clear error flags

		std::cout << std::endl;
	}
}