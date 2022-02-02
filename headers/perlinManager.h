#pragma once
#include "headers/algorithmManager.h"
#include <QCheckBox>
#include <QDoubleSpinBox>
#include <QSpinBox>

class PerlinNoiseManager : public AlgorithmManager
{
  public:
    QSpinBox* widthSpinbox;
    QSpinBox* heightSpinbox;
    QCheckBox* useSeedCheckbox;
    QSpinBox* seedSpinbox;
    QDoubleSpinBox* scaleSpinBox;

  public:
    PerlinNoiseManager(QWidget* parent = nullptr);
    Grid<int> generate() override;
};