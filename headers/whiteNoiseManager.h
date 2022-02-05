#pragma once
#include "headers/algorithmManager.h"
#include <QCheckBox>
#include <QFormLayout>
#include <QSpinBox>

class WhiteNoiseManager : public AlgorithmManager
{
    Q_OBJECT
  public:
    QFormLayout* formLayout;
    QSpinBox* widthSpinbox;
    QSpinBox* heightSpinbox;
    QSpinBox* percentSpinbox;
    QSpinBox* seedSpinbox;
    QCheckBox* useRandomSeedCheckbox;

  public:
    WhiteNoiseManager(QWidget* parent = nullptr);
    Grid<int> generate() override;
  public slots:
    void onUseRandomSeedCheckboxStateChanged(int state);
};