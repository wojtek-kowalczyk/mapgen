#pragma once
#include "headers/algorithmManager.h"
#include <QComboBox>
#include <QGroupBox>
#include <QPushButton>
#include <QWidget>
#include <map>

class SettingsPanel : public QGroupBox
{
    Q_OBJECT
  private:
    QComboBox* dropdown; // this could maybe store Pointer to algorithmManager in QVariant? (metatypes & stuff)
    QPushButton* generateButton;
    // QPushButton* saveButton;
    AlgorithmManager* activeAlgorithmManager;
    std::map<int, AlgorithmManager*> dropdownIndexToAlgManPtr;

  public:
    SettingsPanel(QWidget* parent);
  public slots:
    void onGenerateButtonClicked();
    void onSaveButtonClicked();
    void selectAlgorithm(int);
  signals:
    void requestPreviewImageChange(QImage* newImage);
};