#pragma once
#include "GridObject.h"

namespace Roundbeargames
{
    class Player : public GridObject
    {
    public:
        Player()
        {
            std::cout << "creating player.." << std::endl;
            objType = GridObjType::PLAYER;
            symbol = 'p';
        }
    };
}