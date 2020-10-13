#include <iostream>

int main()
{
	int x = 0;

	if (x < 0)
	{
		std::cout << "it's below zero" << std::endl;
	}
	else if (x == 0)
	{
		std::cout << "it IS zero" << std::endl;
	}
	else
	{
		std::cout << "it's above zero" << std::endl;
	}

	float y = 3.14;

	if (y == 3.14)
	{
		std::cout << "y is 3.14" << std::endl;
	}
}