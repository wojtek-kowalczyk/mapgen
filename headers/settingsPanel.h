#pragma once
#include "headers/whiteNoiseSP.h"
#include <QComboBox>
#include <QGroupBox>
#include <QPushButton>
#include <QWidget>

class SettingsPanel : public QGroupBox
{
    Q_OBJECT
  private:
    QComboBox* dropdown;
    QPushButton* generateButton;
    // QPushButton* saveButton;
    Generator* activeGenerator;

  public:
    SettingsPanel(QWidget* parent);
  public slots:
    void onGenerateButtonClicked();
    void onSaveButtonClicked();
  signals:
    void requestPreviewImageChange(QImage* newImage);
};