# Map Generator

A simple GUI app to generate, fiddle with and save Texture Maps.
Built with [Qt framework](https://qt.io).

Implemented Algorithms:

- White Noise
- Cellular Automata
- OpenSimplex2F
- Perlin Noise
- Voronoi

Planned Fetures:

- Multithreading

## Credits

The C++ implementation of Perlin Noise was taken from: https://github.com/sol-prog/Perlin_Noise.
See [this article](https://solarianprogrammer.com/2012/07/18/perlin-noise-cpp-11/) for more info.

The C implementation of Open Simplex Noise was taken from https://github.com/MarcoCiaramella/OpenSimplex2

## Download and run (Windows only)

Download the `MapGen.zip` file, extract and run the executable.

## Building

Tested on linux (5.15.6-arch2-1), no Qt Creator

Qt version 5.15.2, qmake version 3.1.

[link to Qt Docs](https://doc.qt.io/qt-5.15/gettingstarted.html)

```
qmake -project QT+=widgets
qmake
make
```
