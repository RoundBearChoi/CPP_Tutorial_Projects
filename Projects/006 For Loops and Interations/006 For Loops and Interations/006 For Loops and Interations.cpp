#include <iostream>

int main()
{
	int hp = 5;
	int AllAxes[5] = { 100, 101, 102, 103, 104 };

	std::cout << "your health bar: ";

	for (int i = 0; i < hp; i++)
	{
		std::cout << "бс" ;
	}

	std::cout << std::endl;

	std::cout << "Axe: " << AllAxes[0] << std::endl;
	std::cout << "Axe: " << AllAxes[1] << std::endl;
	std::cout << "Axe: " << AllAxes[2] << std::endl;
	std::cout << "Axe: " << AllAxes[3] << std::endl;
	std::cout << "Axe: " << AllAxes[4] << std::endl;

	std::cout << std::endl;

	for (int i = 0; i < std::size(AllAxes); i++)
	{
		std::cout << "Axe: " << AllAxes[i] << std::endl;
	}
}