#pragma once

template <typename T> class Grid
{
  public:
    T** data;
    int width;
    int height;

  public:
    Grid(int width, int height);
    ~Grid();
    Grid(const Grid& other);
    Grid& operator=(const Grid& other);
    T* operator[](int idx);
};

template <typename T> Grid<T>::Grid(int width, int height)
{
    this->width = width;
    this->height = height;
    data = new T*[width];
    for (int i = 0; i < width; i++)
    {
        data[i] = new T[height];
    }
}

template <typename T> Grid<T>::Grid(const Grid<T>& other)
{
    this->width = other.width;
    this->height = other.height;
    this->data = new T*[this->width];
    for (int i = 0; i < this->width; i++)
    {
        this->data[i] = new T[this->height];
        for (int j = 0; j < this->height; j++)
        {
            this->data[i][j] = other.data[i][j];
        }
    }
}

template <typename T> Grid<T>::~Grid()
{
    for (int i = 0; i < width; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}

template <typename T> Grid<T>& Grid<T>::operator=(const Grid& other)
{
    if (&other == this)
        return *this;

    for (int i = 0; i < width; i++)
    {
        delete[] data[i];
    }
    delete[] data;

    this->width = other.width;
    this->height = other.height;
    this->data = new T*[this->width];
    for (int i = 0; i < this->width; i++)
    {
        this->data[i] = new T[this->height];
        for (int j = 0; j < this->height; j++)
        {
            this->data[i][j] = other.data[i][j];
        }
    }

    return *this;
}

// this allows us to write grid[i][j]
template <typename T> T* Grid<T>::operator[](int idx)
{
    return this->data[idx];
}