#include <iostream>

int main()
{
	int hp = 20;
	bool isDead = true;

	int xPos = 1078523331;
	float xPosition = 3.14;

	std::cout << "your hp is: " << hp << std::endl;

	hp--;

	std::cout << "your hp is now: " << hp << std::endl;

	hp++;

	std::cout << "your hp is up: " << hp << std::endl;

	std::cout << "am i dead? " << isDead << std::endl;

	std::cout << "your xPosition is: " << xPosition << std::endl;

	// human readability
}