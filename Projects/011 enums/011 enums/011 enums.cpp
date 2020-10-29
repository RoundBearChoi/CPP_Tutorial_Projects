#include <iostream>

enum AxeType
{
	Small_Axe,
	Medium_Axe,
	Large_Axe,
};

struct Axe
{
	AxeType axeType;

	void Describe()
	{
		if (axeType == Small_Axe)
		{
			std::cout << "this is a weapon for beginners" << std::endl;
		}
		else if (axeType == Medium_Axe)
		{
			std::cout << "this is a weapon for intermediates" << std::endl;
		}
		else if (axeType == Large_Axe)
		{
			std::cout << "this is a weapon for veterans" << std::endl;
		}
	}
};

int main()
{
	Axe hobbitAxe{ Small_Axe };
	Axe humanAxe{ Medium_Axe };
	Axe dwarvenAxe{ Large_Axe };

	hobbitAxe.Describe();
	humanAxe.Describe();
	dwarvenAxe.Describe();
}