#include <iostream>
#include <vector>

class Enemy
{
	char name[20];
	int hp = 0;
};

int main()
{
	// size is fixed
	int intArr[50];

	intArr[0] = 0;
	intArr[1] = 1;
	intArr[2] = 2;
	intArr[3] = 3;
	intArr[4] = 4;
	intArr[5] = 5;
	intArr[6] = 6;
	intArr[7] = 7;

	// size is NOT fixed
	std::vector<int> intVec;

	//intVec.reserve(20);

	intVec.push_back(0);
	intVec.push_back(1);
	intVec.push_back(2);
	intVec.push_back(3);
	intVec.push_back(4);
	intVec.push_back(5);
	intVec.push_back(6);
	intVec.push_back(7);
	intVec.push_back(8);
	intVec.push_back(9);
	intVec.push_back(10);
	intVec.push_back(11);
	intVec.push_back(12);
	intVec.push_back(13);
	intVec.push_back(14);
	intVec.push_back(15);
	intVec.push_back(16);
	intVec.push_back(17);
	intVec.push_back(18);
	intVec.push_back(19);

	std::vector<Enemy> enemyVec;

	Enemy e0;
	Enemy e1;
	Enemy e2;

	enemyVec.push_back(e0);
	enemyVec.push_back(e1);
	enemyVec.push_back(e2);
}