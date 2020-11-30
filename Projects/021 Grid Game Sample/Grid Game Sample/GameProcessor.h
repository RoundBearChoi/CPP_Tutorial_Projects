#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "PlayerInput.h"
#include "CharacterController.h"

class GameProcessor
{
private:
    Scene scene;
    Renderer renderer;
    PlayerInput input;
    CharacterController characterController;
    char inputChar = '0';

public:
    void Run()
    {
        scene.CreateObject(GridObjType::PLAYER);
        scene.CreateObject(GridObjType::ITEM);
        scene.CreateObject(GridObjType::ENEMY);

        scene.GetObject(GridObjType::PLAYER)->SetPosition(1, 4);
        scene.GetObject(GridObjType::ITEM)->SetPosition(2, 2);
        scene.GetObject(GridObjType::ENEMY)->SetPosition(6, 7);

        while (inputChar != 'q')
        {
            characterController.MovePlayer(inputChar, scene);

            renderer.AddEmptyLines(20);
            renderer.RenderObjImage(scene);
            renderer.RenderScene(scene);
            inputChar = input.GetInput();
        }
    }
};