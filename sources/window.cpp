#include "headers/window.h"
#include "headers/config.h"
#include <QHBoxLayout>

Window::Window(QWidget* parent) : QWidget{parent}
{
    currentImage = nullptr;
    previewLabel = new QLabel(this);
    previewLabel->setMinimumSize(300, 300);
    previewLabel->setAlignment(Qt::AlignCenter);
    previewLabel->setPixmap(QPixmap::fromImage(
        QImage{config::DEFAULT_PREVIEW_WIDTH, config::DEFAULT_PREVIEW_HEIGHT, QImage::Format_Grayscale8}));
    SettingsPanel* settingsPanel = new SettingsPanel(this);
    QObject::connect(settingsPanel, SIGNAL(requestPreviewImageChange(QImage*)), this,
                     SLOT(changePreviewImage(QImage*)));

    QHBoxLayout* windowLayout = new QHBoxLayout(this);
    windowLayout->addWidget(previewLabel);
    windowLayout->addWidget(settingsPanel);
}

void Window::changePreviewImage(QImage* img)
{
    if (currentImage)
        delete currentImage;
    currentImage = img;
    this->previewLabel->setPixmap(QPixmap::fromImage(*currentImage).scaled(previewLabel->size(), Qt::KeepAspectRatio));
}

void Window::cleanup()
{
    if (currentImage)
        delete currentImage;
}

void Window::resizeEvent(QResizeEvent* event)
{
    // I need this because previewLabel->setScaledContents(true) doesn't preserve aspect ratio (and adds filtering?)
    // https://stackoverflow.com/questions/37708062/qt-qpixmap-scaling-incorrectly
    if (currentImage)
    {
        previewLabel->setPixmap(QPixmap::fromImage(*currentImage).scaled(previewLabel->size(), Qt::KeepAspectRatio));
    }
    else
    {
        // so that the black placeholder also scales
        previewLabel->setPixmap(previewLabel->pixmap()->scaled(previewLabel->size(), Qt::KeepAspectRatio));
    }
}