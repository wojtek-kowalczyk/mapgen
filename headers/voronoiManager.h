#pragma once
#include "headers/algorithmManager.h"
#include <QCheckBox>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QSpinBox>

class VoronoiManager : public AlgorithmManager
{
    Q_OBJECT
  private:
    QFormLayout* formLayout;
    QSpinBox* widthSpinbox;
    QSpinBox* heightSpinbox;
    QSpinBox* pointsSpinbox;
    QSpinBox* seedSpinbox;
    QCheckBox* useRandomSeedCheckbox;
    QDoubleSpinBox* exponentSpinbox;

  public:
    VoronoiManager(QWidget* parent = nullptr);
    Grid<int> generate() override;
  public slots:
    void onUseRandomSeedCheckboxStateChanged(int state);
};