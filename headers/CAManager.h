#pragma once
#include "headers/algorithmManager.h"
#include <QCheckBox>
#include <QSpinBox>

class CellularAutomataManager : public AlgorithmManager
{
  public:
    QSpinBox* widthSpinbox;
    QSpinBox* heightSpinbox;
    QSpinBox* percentSpinbox;
    QSpinBox* iterationsSpinbox;
    QSpinBox* neighborsRuleSpinBox;
    QCheckBox* tilingCheckBox;
    QCheckBox* whiteBorderCheckBox;

  public:
    CellularAutomataManager(QWidget* parent = nullptr);
    Grid<int> generate() override;
};