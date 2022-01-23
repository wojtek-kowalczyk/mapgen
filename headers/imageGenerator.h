#pragma once
#include <QImage>

// Converts a grid of [0,1] int values into a BLack-White QImage
QImage dataToImage(int** data, int width, int height);
// Converts a grid of [0-1] float values into a GrayScale QImage
QImage dataToImage(float** data, int width, int height);