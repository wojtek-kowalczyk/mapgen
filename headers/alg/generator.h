#pragma once
#include "headers/alg/grid.h"

/*
 * The idea is that this class is extended by a GUI component that has members which represent settings
 * for a given algorithm. The component exposes them for the user to set, and when requested to generate,
 * the generate method of this interface is called, and it takes the members, 'packages' them into an
 * algorithm function call (thus making algorithm functions completely separate and reusable), and receives
 * Grid of values (most likely floats or ints) to work with.
 */

// Interface
template <typename T> class Generator
{
  public:
    virtual Grid<T> generate() = 0;
};