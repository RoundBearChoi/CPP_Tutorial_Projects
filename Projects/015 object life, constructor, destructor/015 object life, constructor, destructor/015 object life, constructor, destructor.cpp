#include <iostream>

class Character
{
public:
	Character()
	{
		std::cout << "character is created." << std::endl;
	}

	~Character()
	{
		std::cout << "character is destroyed." << std::endl;
	}
};

class Scene
{
public:
	void CreateCharacter()
	{
		std::cout << "character creation (function)" << std::endl;
		Character character;
	}

	Scene()
	{
		std::cout << "scene is created." << std::endl;
	}

	~Scene()
	{
		std::cout << "scene is destroyed." << std::endl;
	}
};

int main()
{
	Scene scene;
	scene.CreateCharacter();
}