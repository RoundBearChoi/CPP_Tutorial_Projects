#include <iostream>
#include <vector>

class Enemy
{
public:
    int index = 0;
};

class EnemyContainer
{
public:
    std::vector<Enemy> vecEnemies;

    void GetEnemies()
    {
        for (int i = 0; i < vecEnemies.size(); i++)
        {
            std::cout << "enemy: " << vecEnemies[i].index << std::endl;
        }

        //for (Enemy e : vecEnemies)
        //{
        //    std::cout << "enemy: " << e.index << std::endl;
        //}
    }

    Enemy* GetEnemy(int targetIndex)
    {
        //for (Enemy e : vecEnemies)
        //{
        //    if (e.index == targetIndex)
        //    {
        //        return &e;
        //    }
        //}

        for (int i = 0; i < vecEnemies.size(); i++)
        {
            if (vecEnemies[i].index == targetIndex)
            {
                return &vecEnemies[i];
            }
        }

        return nullptr;
    }

    void SomeFunction(Enemy e)
    {

    }

    EnemyContainer()
    {
        Enemy e0;
        Enemy e1;
        Enemy e2;

        e0.index = 0;
        e1.index = 1;
        e2.index = 2;

        vecEnemies.push_back(e0);
        vecEnemies.push_back(e1);
        vecEnemies.push_back(e2);
    }
};

int main()
{
    EnemyContainer container;
    container.GetEnemies();

    Enemy* ptr = container.GetEnemy(2);

    std::cout << "enemy #2: " << ptr->index << std::endl;
}