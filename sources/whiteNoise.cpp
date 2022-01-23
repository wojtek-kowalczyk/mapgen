#include "headers/whiteNoise.h"
#include <cstdlib>
#include <ctime>

WhiteNoiseSettingsPanel::WhiteNoiseSettingsPanel(QWidget* parent) : QGroupBox{parent}
{
}

Grid<int> WhiteNoiseSettingsPanel::generate()
{
    srand(time(nullptr));
    Grid<int> grid{width, height};
    for (int i = 0; i < grid.width; i++)
    {
        for (int j = 0; j < grid.height; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }
    return grid;
}
