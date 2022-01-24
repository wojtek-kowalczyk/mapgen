#include "headers/window.h"
#include "headers/config.h"
#include <QHBoxLayout>

Window::Window(QWidget* parent) : QWidget{parent}
{
    previewLabel = new QLabel(this);
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
    this->previewLabel->setPixmap(QPixmap::fromImage(*img).scaled(config::DEFAULT_PREVIEW_WIDTH,
                                                                  config::DEFAULT_PREVIEW_HEIGHT, Qt::KeepAspectRatio));
}