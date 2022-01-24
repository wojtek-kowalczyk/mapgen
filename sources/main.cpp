#include "headers/settingsPanel.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

#include "headers/imageGenerator.h"
#include "headers/whiteNoiseSP.h"

int main(int argc, char* argv[])
{
    QApplication app{argc, argv};
    QWidget window;

    QLabel* previewLabel = new QLabel(&window);
    QImage placeholder{"small.png"};
    // temp
    WhiteNoiseSettingsPanel whiteNoiseGenerator{};
    Grid<int> imageData = whiteNoiseGenerator.generate();
    // QImage image{dataToImage(imageData, 30, 30)};

    previewLabel->setAlignment(Qt::AlignCenter);
    previewLabel->setPixmap(QPixmap::fromImage(placeholder).scaled(600, 600, Qt::KeepAspectRatio));

    SettingsPanel* settingsPanel = new SettingsPanel(&window);

    QHBoxLayout* windowLayout = new QHBoxLayout(&window);
    windowLayout->addWidget(previewLabel);
    windowLayout->addWidget(settingsPanel);

    window.show();
    return app.exec();
}