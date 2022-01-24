#include "headers/imageGenerator.h"

QImage dataToImage(int** data, int width, int height)
{
    QImage img{width, height, QImage::Format_Grayscale8};
    for (int i = 0; i < 256; i++)
    {
        img.setColor(i, qRgb(i, i, i));
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            img.setPixel(i, j, img.colorTable()[data[i][j]]);
        }
    }
    return img;
}