#include "alg/headers/whiteNoise.h"

Grid<int> whiteNoise(int width, int height, int onesPercent)
{
    srand(time(nullptr));
    Grid<int> grid{width, height};
    for (int i = 0; i < grid.width; i++)
    {
        for (int j = 0; j < grid.height; j++)
        {
            int roll = rand() % 100;
            if (onesPercent > roll)
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
        }
    }
    return grid;
}