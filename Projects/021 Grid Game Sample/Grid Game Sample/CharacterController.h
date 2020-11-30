#pragma once
#include "Scene.h"

class CharacterController
{
public:
    void MovePlayer(char inputChar, Scene& scene)
    {
        if (inputChar == 'w')
        {
            scene.GetObject(GridObjType::PLAYER)->MoveWest();
        }
        else if (inputChar == 'e')
        {
            scene.GetObject(GridObjType::PLAYER)->MoveEast();
        }
        else if (inputChar == 'n')
        {
            scene.GetObject(GridObjType::PLAYER)->MoveNorth();
        }
        else if (inputChar == 's')
        {
            scene.GetObject(GridObjType::PLAYER)->MoveSouth();
        }
    }
};