#pragma once
#include <QImage>

// Converts a grid of [0,255] int values into greyscale QImage
QImage dataToImage(int** data, int width, int height);