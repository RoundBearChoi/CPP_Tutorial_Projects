#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "CharacterController.h"

class GameProcessor
{
private:
    Scene scene;
    Renderer renderer;
    CharacterController characterController;

public:
    void Run()
    {
        scene.CreateObject(GridObjType::PLAYER);
        scene.CreateObject(GridObjType::ITEM);
        scene.CreateObject(GridObjType::ENEMY);

        scene.GetObject(GridObjType::PLAYER)->SetPosition(1, 4);
        scene.GetObject(GridObjType::ITEM)->SetPosition(2, 2);
        scene.GetObject(GridObjType::ENEMY)->SetPosition(6, 7);

        while (characterController.GetInputCharacter() != 'q')
        {
            renderer.AddEmptyLines(20);
            renderer.RenderObjImage(scene);
            renderer.RenderScene(scene);

            characterController.MovePlayer(scene);
        }
    }
};