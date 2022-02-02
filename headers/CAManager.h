#pragma once
#include "headers/algorithmManager.h"
#include <QCheckBox>
#include <QFormLayout>
#include <QSpinBox>
class CellularAutomataManager : public AlgorithmManager
{
    Q_OBJECT
  private:
    QFormLayout* formLayout;
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
  public slots:
    void onTilingCheckboxStateChange(int);
};