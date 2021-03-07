#include <iostream>

class Enemy
{
private:
	int index = 0;
public:
	Enemy(int newIndex)
	{
		std::cout << "enemy is constructed: " << newIndex << std::endl;
		index = newIndex;
	}

	~Enemy()
	{
		std::cout << "enemy is destructed: " << index << std::endl;
	}
};

class Scene
{
public:
	void CreateEnemy()
	{
		Enemy e0(0);
		Enemy e1(1);
		Enemy e2(2);

		std::cout << "do something" << std::endl;

		Enemy* e3 = new Enemy(3);
		Enemy* e4 = new Enemy(4);

		//new Enemy(5);

		std::cout << "do another thing" << std::endl;

		delete e3;
		delete e4;

		std::cout << "yet do another" << std::endl;
	}

	Scene()
	{
		std::cout << "scene is constructed." << std::endl;
	}

	~Scene()
	{
		std::cout << "scene is destructed." << std::endl;
	}
};

int main()
{
	Scene scene;
	scene.CreateEnemy();
}