#pragma once

#include "headers/settingsPanel.h"
#include <QImage>
#include <QLabel>
#include <QWidget>

class Window : public QWidget
{
    Q_OBJECT
  private:
    QLabel* previewLabel;
    SettingsPanel* settingsPanel;

  public:
    Window(QWidget* parent = nullptr);
  public slots:
    void changePreviewImage(QImage*);
};