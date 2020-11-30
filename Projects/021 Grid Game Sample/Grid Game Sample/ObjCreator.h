#pragma once
#include <vector>
#include "Player.h"
#include "Item.h"
#include "Enemy.h"

class ObjCreator
{
private:
    std::vector<GridObject*> ObjPtrs;

public:
    void CreateObj(GridObjType objType)
    {
        for (GridObject* obj : ObjPtrs)
        {
            if (obj->GetType() == objType)
            {
                throw "Object type already exists..";
            }
        }

        if (objType == GridObjType::PLAYER)
        {
            Player* player = new Player();
            ObjPtrs.push_back(player);
        }
        else if (objType == GridObjType::ITEM)
        {
            Item* item = new Item();
            ObjPtrs.push_back(item);
        }
        else if (objType == GridObjType::ENEMY)
        {
            Enemy* enemy = new Enemy();
            ObjPtrs.push_back(enemy);
        }
    }

    GridObject* GetObj(GridObjType targetType)
    {
        for (GridObject* obj : ObjPtrs)
        {
            if (obj->GetType() == targetType)
            {
                return obj;
            }
        }

        throw "Object type not found";
    }

    char GetSym(int x, int y)
    {
        for (GridObject* obj : ObjPtrs)
        {
            Vec2 pos = obj->GetPosition();

            if (pos.x == x &&
                pos.y == y)
            {
                return obj->GetSymbol();
            }
        }

        // return default grid symbol if nothing matches
        return '.';
    }

    void DeleteAll()
    {
        for (GridObject* obj : ObjPtrs)
        {
            delete obj;
        }
    }
};