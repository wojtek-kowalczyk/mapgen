
/*
 *  This is not a vector voronoi implementation, you cannot offset and move the map like in the case of OpenSimplex2F
 *  This is a naive implementation, where we blindly compute a distance function from evvery pixel to a given point.
 *
 *  Possible changes:
 *  - use different distance functions
 *  - compute a small image with the algorithm, and upscale it with Qt, depending on which is faster
 *
 */

#include "alg/headers/algorithms.h"
#include <cmath>
#include <limits>

struct Vector2
{
    int x;
    int y;
};

inline float sqr_distance(Vector2 a, Vector2 b)
{
    // euclidean distance
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

inline float distance(Vector2 a, Vector2 b)
{
    return std::sqrt(sqr_distance(a, b));
}

// helper - maps the value in range [a,b] to a value in range [A,B], linearly
inline double map(double val, double a, double b, double A, double B)
{
    return (A + ((B - A) / (b - a)) * (val - a));
}

Vector2 nearestNeighbor(Vector2 origin, const Vector2* points, int numPoints)
{
    // naive approach (scan all, take least, slow but easy to implement)
    Vector2 nn{0, 0};
    float min{std::numeric_limits<float>::infinity()};
    float currDistance{};
    for (int i = 0; i < numPoints; i++)
    {
        currDistance = sqr_distance(origin, points[i]);
        if (currDistance < min)
        {
            min = currDistance;
            nn = points[i];
        }
    }
    return nn;
}

Grid<int> voronoi(int width, int height, int numPoints, unsigned int seed)
{
    Grid<int> pixels{width, height};
    float min{std::numeric_limits<float>::infinity()};
    float max{-std::numeric_limits<float>::infinity()};
    float dist{0};
    Vector2 currPoint;

    srand(seed);
    Vector2 points[numPoints];
    for (int i = 0; i < numPoints; i++)
    {
        points[i].x = rand() % width;
        points[i].y = rand() % height;
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            currPoint.x = i;
            currPoint.y = j;
            dist = distance(nearestNeighbor(currPoint, points, numPoints), currPoint);
            pixels[i][j] = dist;

            if (dist < min)
                min = dist;

            if (dist > max)
                max = dist;
        }
    }

    // since pixels stores distances now, I have to map them between 0 and 255
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            pixels[i][j] = static_cast<int>(map(pixels[i][j], min, max, 0, 255));
        }
    }

    return pixels;
}