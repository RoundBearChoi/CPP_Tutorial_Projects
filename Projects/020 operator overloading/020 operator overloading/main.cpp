#include <iostream>

class Vector2
{
public:
	int x = 0;
	int y = 0;

	Vector2 operator+ (Vector2 targetVec)
	{
		Vector2 result;

		result.x = x + targetVec.x;
		result.y = y + targetVec.y;

		return result;
	}
};

class Vector3
{
	float x;
	float y;
	float z;
};

int main()
{
	Vector2 a;
	Vector2 b;

	a.x = 1;
	a.y = 2;

	b.x = 1;
	b.y = 1;

	Vector2 result;

	result = a + b;

	// HW: try overloading + - == etc
	// try creating Vector3, 4, 5, 6, etc

	//result = b - a;
	//result = a - b;
	//
	//if (a == b)
	//{
	//
	//}
}