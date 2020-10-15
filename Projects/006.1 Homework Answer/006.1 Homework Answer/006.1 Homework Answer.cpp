#include <iostream>

struct Multiplier
{
    void ShowTable(int front)
    {
        for (int back = 1; back <= 10; back++)
        {
            std::cout << front << " * " << back << " = " << front * back << std::endl;
        }

        std::cout << std::endl;
    }
};

int main()
{
    //Multiplier multiplier;
    //
    //multiplier.ShowTable(1);
    //multiplier.ShowTable(2);
    //multiplier.ShowTable(3);
    //multiplier.ShowTable(4);
    //multiplier.ShowTable(5);
    //multiplier.ShowTable(6);
    //multiplier.ShowTable(7);
    //multiplier.ShowTable(8);
    //multiplier.ShowTable(9);
    //multiplier.ShowTable(10);
    //multiplier.ShowTable(11);
    //multiplier.ShowTable(12);

    for (int front = 1; front <= 12; front++)
    {
        for (int back = 1; back <= 10; back++)
        {
            std::cout << front << " * " << back << " = " << front * back << std::endl;
        }

        std::cout << std::endl;
    }
}