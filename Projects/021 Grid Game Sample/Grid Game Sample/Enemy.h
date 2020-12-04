#pragma once
#include "GridObject.h"

namespace Roundbeargames
{
    class Enemy : public GridObject
    {
    public:
        Enemy()
        {
            std::cout << "creating enemy.." << std::endl;
            objType = GridObjType::ENEMY;
            symbol = 'e';
        }
    };
}