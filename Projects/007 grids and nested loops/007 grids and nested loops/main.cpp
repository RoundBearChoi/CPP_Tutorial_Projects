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
					std::cout << "♣";
				}
				else
				{
					std::cout << "□";
				}
			}

			std::cout << std::endl;
		}
	}
};

int main()
{
	Grid grid{ 8, 12 };
	GridObject obj{ 3, 6 };

	grid.Render(obj);
}