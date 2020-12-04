#include <iostream>
#include "ItemRender.h"
#include "RandomInteger.h"
#include "Shuffle.h"

int main()
{
	Roundbeargames::ItemRender itemRender;
	itemRender.Render();

	Roundbeargames::RandomInteger randomInteger;
	for (int i = 0; i < 20; i++)
	{
		std::cout << randomInteger.GetInteger(0, 2) << std::endl;
	}

	std::cout << std::endl;

	Roundbeargames::Shuffle shuffle;
	std::vector<int> someVec{ 0, 1, 2, 3, 4, 5 };
	shuffle.Randomize(someVec);

	for (int i = 0; i < someVec.size(); i++)
	{
		std::cout << someVec[i] << std::endl;
	}
}