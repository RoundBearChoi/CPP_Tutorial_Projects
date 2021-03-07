#include <iostream>

int main()
{
	char arrChars[128] = { 'c', 'a', 't' };

	std::cout << "enter your name: ";

	std::cin.width(sizeof(arrChars));

	std::cin >> arrChars;

	std::cout << std::endl;

	std::cout << "your name is: " << arrChars << std::endl;

	std::cout << std::endl;
}