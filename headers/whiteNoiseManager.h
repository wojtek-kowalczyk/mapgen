#pragma once
#include "headers/algorithmManager.h"
#include <QSpinBox>

class WhiteNoiseManager : public AlgorithmManager
{
  public:
    QSpinBox* widthSpinbox;
    QSpinBox* heightSpinbox;
    QSpinBox* percentSpinbox;

  public:
    WhiteNoiseManager(QWidget* parent = nullptr);
    Grid<int> generate() override;
};