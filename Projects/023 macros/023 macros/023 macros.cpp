#include <iostream>

#define MY_INTEGER 10

//#define CREATE_INTEGER int n = 5;

#define CREATE_FLOAT float f = 0.5f;

int main()
{
	std::cout << MY_INTEGER << std::endl;

#ifdef CREATE_INTEGER
	CREATE_INTEGER
		std::cout << n << std::endl;
#else
	std::cout << "CREATE_INTEGER is not defined" << std::endl;
#endif

#ifndef CREATE_FLOAT
	std::cout << "CREATE_FLOAT is not defined" << std::endl;
#else
	CREATE_FLOAT
		std::cout << f << std::endl;
#endif
}