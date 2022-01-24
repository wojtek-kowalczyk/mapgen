#pragma once
#include "alg/headers/grid.h"
#include <cstdlib>
#include <ctime>

// this might not be a book-example of white noise due to ability to change fill percent, but I do like the name.

// setting onesPercent to value >= 100 will yield all 1s.
// setting onesPercent to value <= 0 will yield all 0s
Grid<int> whiteNoise(int width, int height, int onesPercent = 50);