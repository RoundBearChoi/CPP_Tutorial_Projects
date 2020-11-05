#include <iostream>

struct WeaponS
{
//public:
	int GetDamage()
	{
		return damage;
	}
private:
	int damage = 1;
};

class WeaponC
{
//private:
	int damage = 1;
public:
	int GetDamage()
	{
		return damage;
	}
};

int main()
{
	WeaponS s;
	WeaponC c;

	std::cout << "weaponS damage: " << s.GetDamage() << std::endl;
	std::cout << "weaponC damage: " << c.GetDamage() << std::endl;
}