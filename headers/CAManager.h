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
    QSpinBox* seedSpinbox;
    QSpinBox* neighborsRuleSpinBox;
    QCheckBox* tilingCheckBox;
    QCheckBox* whiteBorderCheckBox;
    QCheckBox* useRandomSeedCheckbox;

  public:
    CellularAutomataManager(QWidget* parent = nullptr);
    Grid<int> generate() override;
  public slots:
    void onTilingCheckboxStateChange(int);
    void onUseRandomSeedCheckboxStateChanged(int state);
};