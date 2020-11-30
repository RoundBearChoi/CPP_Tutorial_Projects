#pragma once
#include <iostream>


class PlayerInput
{
private:
	std::string yourString;
public:
	char GetInput()
	{
		std::cin >> yourString;
		return yourString[0];
	}
};