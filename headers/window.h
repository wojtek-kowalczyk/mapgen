#pragma once

#include "headers/settingsPanel.h"
#include <QImage>
#include <QLabel>
#include <QResizeEvent>
#include <QWidget>

class Window : public QWidget
{
    Q_OBJECT
  private:
    QLabel* previewLabel;
    SettingsPanel* settingsPanel;

  public:
    QImage* currentImage; // so that we save 8bit image and not 32bit pixmap
    Window(QWidget* parent = nullptr);
    void resizeEvent(QResizeEvent*) override;
  public slots:
    void changePreviewImage(QImage*);
    void saveImage(QString path);
    void cleanup();
};