#include <iostream>

int main()
{
	char arrChar[2];
	bool quitGame = false;

	arrChar[0] = '0';

	while (quitGame == false)
	{
		std::cout << "say something: ";

		std::cin.width(sizeof(arrChar));

		std::cin >> arrChar;

		std::cout << "you said: " << arrChar[0] << std::endl;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (arrChar[0] == 'q')
		{
			quitGame = true;
		}

		std::cout << std::endl;
	}
}