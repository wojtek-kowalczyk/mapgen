#include "headers/settingsPanel.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

#include "headers/imageGenerator.h"
#include "headers/whiteNoise.h"

int main(int argc, char* argv[])
{
    QApplication app{argc, argv};
    QWidget window;

    QLabel* previewLabel = new QLabel(&window);
    QImage placeholder{"small.png"};
    // temp
    WhiteNoiseSettingsPanel whiteNoiseGenerator{};
    whiteNoiseGenerator.width = 30;
    whiteNoiseGenerator.height = 30;
    Grid<int> imageData = whiteNoiseGenerator.generate(); // free this
    QImage image{dataToImage(imageData, 30, 30)};

    previewLabel->setAlignment(Qt::AlignCenter);
    previewLabel->setPixmap(QPixmap::fromImage(image).scaled(600, 600, Qt::KeepAspectRatio));

    SettingsPanel* settingsPanel = new SettingsPanel(&window);

    QHBoxLayout* windowLayout = new QHBoxLayout(&window);
    windowLayout->addWidget(previewLabel);
    windowLayout->addWidget(settingsPanel);

    window.show();
    return app.exec();
}