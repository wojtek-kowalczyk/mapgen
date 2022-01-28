#include "alg/headers/algorithms.h"
#include <iostream>

// function that imitates Python's % operator (i.e -1 % 20 is 19 not -1)
// used for wrap-around.
inline int customMod(int a, int b)
{
    return ((a % b < 0) ? a % b + b : a % b);
}

// todo - might consider adding an enum(or a bitflag) representing edgemode, which
// todo - could be: TILING, WHITE_BORDER, OUT_OF_BOUNDS_ARE_WHITE, etc.

// no bounds checking takes place if tiling is false
inline int countWhiteNeighbors(Grid<int> grid, int x, int y, bool tiling)
{
    int countWhites{0};
    for (int nx = -1; nx < 2; nx++)
    {
        for (int ny = -1; ny < 2; ny++)
        {
            if (nx == 0 && ny == 0)
                continue;
            if (tiling)
            {
                if (grid[customMod(x + nx, grid.width)][customMod(y + ny, grid.height)] == config::WHITE)
                    ++countWhites;
            }
            else
            {
                if (grid[x + nx][y + ny] == config::WHITE)
                {
                    ++countWhites;
                }
            }
        }
    }
    return countWhites;
}

// neighborsRule - how many neighbors of said color there has to be in order for a cell to become that color
Grid<int> CellularAutomaton(Grid<int> initialConfig, bool tiling, bool whiteBorder, int iterations, int neighborsRule)
{
    Grid<int> grid{initialConfig}; // ? can i work on initialConfig directly?
    for (int i = 0; i < iterations; ++i)
    {
        for (int x = 0; x < grid.width; x++)
        {
            for (int y = 0; y < grid.height; y++)
            {
                if ((x == 0 || y == 0 || x == grid.width - 1 || y == grid.height - 1) && !tiling)
                {
                    grid[x][y] = whiteBorder ? config::WHITE : config::BLACK;
                    continue;
                }

                int countWhites{countWhiteNeighbors(grid, x, y, tiling)};
                if (countWhites > neighborsRule)
                    grid[x][y] = config::WHITE;
                else if (countWhites < neighborsRule)
                    grid[x][y] = config::BLACK;
            }
        }
    }
    return grid;
}

Grid<int> CellularAutomaton(int width, int height, int onesPercent, bool tiling, bool whiteBorder, int iterations,
                            int neighborsRule)
{
    return CellularAutomaton(whiteNoise(width, height, onesPercent), tiling, whiteBorder, iterations, neighborsRule);
}