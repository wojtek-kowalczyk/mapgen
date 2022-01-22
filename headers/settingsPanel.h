#pragma once
#include <QGroupBox>
#include <QWidget>

class SettingsPanel : public QGroupBox
{
    Q_OBJECT
  private:
  public:
    SettingsPanel(QWidget* parent);
  public slots:
    void tmp_buttonClick();
};