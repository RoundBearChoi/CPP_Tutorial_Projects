#pragma once
#include <iostream>
#include "GridObjectType.h"
#include "Vec2.h"

namespace Roundbeargames
{

    class GridObject
    {
    protected:
        char symbol = '0';
        Vec2 position;
        GridObjType objType = GridObjType::NONE;

    public:
        void SetPosition(int positionX, int positionY)
        {
            position.x = positionX;
            position.y = positionY;
        }

        void MoveEast()
        {
            position.x += 1;
        }

        void MoveWest()
        {
            position.x -= 1;
        }

        void MoveNorth()
        {
            position.y -= 1;
        }

        void MoveSouth()
        {
            position.y += 1;
        }

        Vec2 GetPosition()
        {
            return position;
        }

        char GetSymbol()
        {
            return symbol;
        }

        GridObjType GetType()
        {
            return objType;
        }

        ~GridObject()
        {
            std::cout << "destroying obj: " << symbol << std::endl;
        }
    };
}