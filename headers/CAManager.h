#pragma once
#include "headers/algorithmManager.h"
#include <QCheckBox>
#include <QSpinBox>
// Grid<int> CellularAutomaton(int width, int height, int onesPercent = 50, bool tiling, bool whiteBorder, int
// iterations,
//                             int neighborsRule = 4);
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