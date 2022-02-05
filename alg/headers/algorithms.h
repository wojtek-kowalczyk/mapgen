#pragma once
#include "alg/headers/grid.h"
#include "headers/config.h"
#include <cstdlib>
#include <ctime>

// this might not be a book-example of white noise due to ability to change fill percent, but I do like the name.

// setting onesPercent to value >= 100 will yield all 1s.
// setting onesPercent to value <= 0 will yield all 0s
Grid<int> whiteNoise(int width, int height, int onesPercent = 50);

Grid<int> CellularAutomaton(Grid<int> initialConfig, bool tiling, bool whiteBorder, int iterations,
                            int neighborsRule = 4);
Grid<int> CellularAutomaton(int width, int height, int onesPercent, bool tiling, bool whiteBorder, int iterations,
                            int neighborsRule = 4);
Grid<int> voronoi(int width, int height, int points, unsigned int seed = 0);