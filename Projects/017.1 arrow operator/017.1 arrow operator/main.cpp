#include <iostream>

class Weapon
{
public:
	int damage = 0;
};

int main()
{
	Weapon weapon;
	Weapon* weaponPtr = &weapon;

	std::cout << weaponPtr->damage << std::endl;
	std::cout << weapon.damage << std::endl;

	int n = 10 + 5;

	std::cout << n << std::endl;
}