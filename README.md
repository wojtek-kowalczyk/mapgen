# Map Generator

A simple GUI app to generate, fiddle with and save Texture Maps.
Built with [Qt framework](https://qt.io).

Implemented Algorithms:

- White Noise
- Cellular Automata

Planned Algorithms:

- Simplex Noise
- Perlin Noise
- Voronoi

Planned Fetures: 
- Multithreading
- Saving maps to a file

## Building

I was working on linux (5.15.6-arch2-1), from the terminal (no Qt Creator)

Qt version 5.15.2, qmake version 3.1.
[link to Qt Docs](https://doc.qt.io/qt-5.15/gettingstarted.html) should you have problems with Qt.

```
qmake -project QT+=widgets
qmake
make
```
