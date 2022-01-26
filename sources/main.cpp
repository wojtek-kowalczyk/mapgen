#include "headers/window.h"
#include <QApplication>

// from https://doc.qt.io/qt-5/qapplication.html#exec :
// We recommend that you connect clean-up code to the aboutToQuit() signal, instead of putting it in your application's
// main() function.
int main(int argc, char* argv[])
{
    QApplication app{argc, argv};
    Window window;
    window.show();
    QObject::connect(&app, SIGNAL(aboutToQuit()), &window, SLOT(cleanup()));
    return app.exec();
}