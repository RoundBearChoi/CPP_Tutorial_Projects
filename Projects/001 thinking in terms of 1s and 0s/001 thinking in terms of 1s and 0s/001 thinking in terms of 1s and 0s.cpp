#include <iostream>

int main()
{
	int hp = 10;
	bool playerIsDead = false;
	float xPosition = 1.5f;
	float f = 4.99999999999999999999999999f;
	float pi = 3.14f;

	std::cout << "player hp is " << hp << std::endl;

	// this is for human readability

	//std::string str;
	//std::cin >> str;

	hp--;

	std::cout << "your hp is now " << hp << std::endl;

	hp++;

	std::cout << "your hp is up " << hp << std::endl;

	std::cout << "is player dead? " << playerIsDead << std::endl;

	std::cout << "player position x: " << xPosition << std::endl;
}