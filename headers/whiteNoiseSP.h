#pragma once
#include "headers/generator.h"
#include <QGroupBox>
#include <QSpinBox>

// this name might be misleading, since apart from being the settings panel for white noise this object is also
// the one responsible for calling the generate function
// might change this later, idk
class WhiteNoiseSettingsPanel : public QGroupBox, public Generator<int>
{
  private:
    QSpinBox* widthSpinbox;
    QSpinBox* heightSpinbox;

  public:
    WhiteNoiseSettingsPanel(QWidget* parent = nullptr);
    Grid<int> generate() override;
};