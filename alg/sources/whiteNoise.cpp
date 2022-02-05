#include "alg/headers/algorithms.h"

Grid<int> whiteNoise(int width, int height, int onesPercent, unsigned int seed)
{
    // srand(time(nullptr) + (++calls));
    srand(seed);
    Grid<int> grid{width, height};
    for (int i = 0; i < grid.width; i++)
    {
        for (int j = 0; j < grid.height; j++)
        {
            int roll = rand() % 100;
            if (onesPercent > roll)
                grid[i][j] = 255;
            else
                grid[i][j] = 0;
        }
    }
    return grid;
}