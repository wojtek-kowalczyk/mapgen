#include "headers/settingsPanel.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

int main(int argc, char* argv[])
{
    QApplication app{argc, argv};
    QWidget window;

    QLabel* previewLabel = new QLabel(&window);
    QImage placeholder{"small.png"};
    previewLabel->setAlignment(Qt::AlignCenter);
    previewLabel->setPixmap(QPixmap::fromImage(placeholder).scaled(600, 600, Qt::KeepAspectRatio));

    SettingsPanel* settingsPanel = new SettingsPanel(&window);

    QHBoxLayout* windowLayout = new QHBoxLayout(&window);
    windowLayout->addWidget(previewLabel);
    windowLayout->addWidget(settingsPanel);

    window.show();
    return app.exec();
}
