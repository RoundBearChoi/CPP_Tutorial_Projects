#include <iostream>
#include "ItemRender.h"
#include "RandomInteger.h"

int main()
{
	Roundbeargames::ItemRender itemRender;
	itemRender.Render();

	Roundbeargames::RandomInteger randomInteger;
	for (int i = 0; i < 20; i++)
	{
		std::cout << randomInteger.GetInteger(0, 2) << std::endl;
	}
}