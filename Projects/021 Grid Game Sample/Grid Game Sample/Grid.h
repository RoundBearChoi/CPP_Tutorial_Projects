#pragma once
#include <vector>
#include "Vec2.h"

namespace Roundbeargames
{
    class Grid
    {
    private:
        Vec2 size;

    public:
        void SetSize(int rowSize, int colSize)
        {
            size.x = rowSize;
            size.y = colSize;
        }

        Vec2 GetSize()
        {
            return size;
        }
    };
}