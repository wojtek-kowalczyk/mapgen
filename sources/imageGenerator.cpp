#include "headers/imageGenerator.h"

QImage dataToImage(int** data, int width, int height)
{
    QImage img{width, height, QImage::Format_Grayscale8};
    QRgb black{qRgb(0, 0, 0)};
    QRgb white{qRgb(255, 255, 255)};
    // add black and white to color table
    img.setColor(0, black);
    img.setColor(1, white);
    // fill the image
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (data[i][j] == 1)
            {
                img.setPixel(i, j, white);
            }
            else
            {
                // ! mind invalid input (not {0,1}) - consider else if + else exception
                img.setPixel(i, j, black);
            }
        }
    }
    return img;
}

QImage dataToImage(float** data, int width, int height)
{
    QImage img{width, height, QImage::Format_Grayscale8};
    return img;
}