#include <iostream>

int main()
{
	int someInt = 5;

	std::cout << "integer value: " << someInt << std::endl;
	std::cout << "integer address: " << &someInt << std::endl;

	int* intPtr = &someInt;

	std::cout << "int pointer: " << intPtr << std::endl;
	std::cout << "int pointer address: " << &intPtr << std::endl;

	std::cout << "int pointer dereference: " << *intPtr << std::endl;
}