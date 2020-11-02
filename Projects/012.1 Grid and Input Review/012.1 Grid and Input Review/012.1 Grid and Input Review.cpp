#include <iostream>

struct GridObject
{
	int x;
	int y;
};

struct Grid
{
	int totalX;
	int totalY;

	void Render(GridObject obj)
	{
		for (int col = 0; col < totalY; col++)
		{
			for (int row = 0; row < totalX; row++)
			{
				if (obj.x == row && obj.y == col)
				{
					std::cout << "P";
				}
				else
				{
					std::cout << ".";
				}
			}

			std::cout << std::endl;
		}
	}
};

struct PlayerInput
{
	std::string yourString;

	char GetInput()
	{
		std::cout << "say something: ";
		std::cin >> yourString;

		std::cout << std::endl;
		std::cout << "you said: " << yourString << std::endl;
		std::cout << "first letter: " << yourString[0] << std::endl;

		std::cin.clear(); // clear error flags

		std::cout << std::endl;

		return yourString[0];
	}
};

int main()
{
	Grid grid;
	grid.totalX = 8;
	grid.totalY = 12;

	GridObject obj;
	obj.x = 3;
	obj.y = 6;

	PlayerInput playerInput;
	char input = '0';

	while (input != 'q')
	{
		grid.Render(obj);

		input = playerInput.GetInput();
		
		if (input == 'w')
		{
			obj.x -= 1;
		}
		else if (input == 'e')
		{
			obj.x += 1;
		}
	}
}