#pragma once

namespace RB
{
    struct Player
    {
        int hp = 5;

        void ShowHP()
        {
            std::cout << "player's hp is " << hp << std::endl;
        }
    };
}