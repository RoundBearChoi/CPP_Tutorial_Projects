#include <iostream>

struct Axe
{
	char name[256] = "no name";
	int damage = 0;
	bool isOnFire = false;

	void HitTarget()
	{
		if (isOnFire == true)
		{
			std::cout << name << " hits target with damage: " << damage + 5 << std::endl;
		}
		else
		{
			std::cout << name << " hits target with damage: " << damage << std::endl;
		}
	}

	void CriticalHitTarget(int criticalInt)
	{
		std::cout << name << " critical hits target with damage: " << criticalInt * damage << std::endl;
	}

	int GetDoubleDamage()
	{
		return damage * 2;
	}
};

int main()
{
	Axe GreatAxe{ "Really Great Axe", 50, false };
	Axe SmallAxe{ "Really Small Axe", 1, false };
	Axe BurningAxe{ "A Burning Axe", 1, true };

	GreatAxe.HitTarget();
	SmallAxe.HitTarget();
	BurningAxe.HitTarget();

	std::cout << "GreatAxe double damage: " << GreatAxe.GetDoubleDamage() << std::endl;

	GreatAxe.CriticalHitTarget(3);
}