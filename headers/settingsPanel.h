#pragma once
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

  public:
    SettingsPanel(QWidget* parent);
  public slots:
    void onGenerateButtonClicked();
    void onSaveButtonClicked();
};