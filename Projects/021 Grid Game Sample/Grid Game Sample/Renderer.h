#pragma once
#include "Scene.h"
#include <vector>
#include <iostream>

namespace Roundbeargames
{
    class Renderer
    {
    public:
        void RenderObjImage(Scene& scene)
        {
            Vec2 playerPos = scene.GetObject(GridObjType::PLAYER)->GetPosition();
            Vec2 itemPos = scene.GetObject(GridObjType::ITEM)->GetPosition();
            Vec2 enemyPos = scene.GetObject(GridObjType::ENEMY)->GetPosition();

            if (playerPos == itemPos)
            {
                std::cout << R"(
                           ___
                          ( ((
                           ) ))
  .::.                    / /(
 '  .-;-.-.-.-.-.-.-.-.-/| ((::::::::::::::::::::::::::::::::::::::::::::::.._
(  ( ( ( ( ( ( ( ( ( ( ( |  ))   -====================================-      _.>
 `  `-;-`-`-`-`-`-`-`-`-\| ((::::::::::::::::::::::::::::::::::::::::::::::''
  `::'                    \ \(
                           ) ))
                          (_((
)" << std::endl;
            }
            else if (playerPos == enemyPos)
            {
                std::cout << R"(
 __         __
/  \.-"""-./  \
\    -   -    /
 |   o   o   |
 \  .-'''-.  /
  '-\__Y__/-'
     `---`
)" << std::endl;
            }
        }

        void RenderScene(Scene& scene)
        {
            Vec2 gridSize = scene.GetGridSize();

            for (int col = 0; col < gridSize.y; col++)
            {
                for (int row = 0; row < gridSize.x; row++)
                {
                    std::cout << scene.GetSymbol(row, col);
                }

                std::cout << std::endl;
            }

            std::cout << std::endl;
        }

        void AddEmptyLines(int count)
        {
            for (int i = 0; i < count; i++)
            {
                std::cout << std::endl;
            }
        }
    };
}