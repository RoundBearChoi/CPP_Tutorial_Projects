#pragma once
#include "GridObject.h"

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