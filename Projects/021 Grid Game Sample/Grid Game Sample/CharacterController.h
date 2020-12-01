#pragma once
#include "Scene.h"
#include "PlayerInput.h"

class CharacterController
{
private:
    PlayerInput playerInput;
    char inputChar = '0';

public:
    char GetInputCharacter()
    {
        return inputChar;
    }

    void MovePlayer(Scene& scene)
    {
        inputChar = playerInput.GetInput();

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