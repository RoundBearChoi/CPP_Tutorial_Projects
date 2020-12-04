#pragma once
#include "GridObject.h"

namespace Roundbeargames
{
    class Item : public GridObject
    {
    public:
        Item()
        {
            std::cout << "creating item.." << std::endl;
            objType = GridObjType::ITEM;
            symbol = 'i';
        }
    };
}