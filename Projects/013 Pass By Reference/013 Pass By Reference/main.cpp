#include <iostream>

struct Player
{
    int x;
    int y;
};

struct Movement
{
    void Move(Player &p)
    {
        p.x += 1;
        p.y += 1;
    }
};

int main()
{
    Player player;
    player.x = 0;
    player.y = 0;

    Movement movement;

    movement.Move(player);
}