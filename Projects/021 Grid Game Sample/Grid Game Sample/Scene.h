#pragma once
#include "Grid.h"
#include "ObjCreator.h"

class Scene
{
private:
    Grid grid;
    ObjCreator objCreator;

public:
    void CreateObject(GridObjType objType)
    {
        objCreator.CreateObj(objType);
    }

    GridObject* GetObject(GridObjType targetType)
    {
        return objCreator.GetObj(targetType);
    }

    Vec2 GetGridSize()
    {
        return grid.GetSize();
    }

    char GetSymbol(int x, int y)
    {
        return objCreator.GetSym(x, y);
    }

    Scene()
    {
        std::cout << "creating scene.." << std::endl;

        grid.SetSize(12, 12);
    }

    ~Scene()
    {
        std::cout << std::endl;
        std::cout << "destroying scene.." << std::endl;

        objCreator.DeleteAll();
    }
};