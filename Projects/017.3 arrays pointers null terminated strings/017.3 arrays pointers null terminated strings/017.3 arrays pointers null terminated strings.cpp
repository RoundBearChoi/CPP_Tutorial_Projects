#include <iostream>

int main()
{
	int arr[] = { 0, 1, 2 };

	std::cout << arr << std::endl;
	std::cout << &arr[0] << std::endl;

	char cArr[] = "here";

	// null terminator, null character, null terminated string
	char h[5] = { 'h', 'e', 'r', 'e', 0 };

	char hh[5];
	hh[0] = 'h';

	std::cout << cArr << std::endl;
	std::cout << &cArr[0] << std::endl;
	std::cout << hh << std::endl;
}