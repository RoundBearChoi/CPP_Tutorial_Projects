#include <iostream>

class SomeObj
{
public:
	const int n = 5;
	const char c[3] = { 'h', 'i', 0 };

	const char* ptr = "hello";
};

int main()
{
	SomeObj someObj;
	//someObj.n = 6;

	std::cout << someObj.c << std::endl;

	//array is the constant. you can change the pointer.
	//someObj.ptr[0] = 'r';
	someObj.ptr = "hello again";

	std::cout << someObj.ptr << std::endl;
}