#pragma once
#include "headers/algorithmManager.h"
#include <QCheckBox>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QSpinBox>

class PerlinNoiseManager : public AlgorithmManager
{
    Q_OBJECT
  private:
    QFormLayout* formLayout;
    QSpinBox* widthSpinbox;
    QSpinBox* heightSpinbox;
    QCheckBox* useSeedCheckbox;
    QSpinBox* seedSpinbox;
    QDoubleSpinBox* scaleSpinBox;

  public:
    PerlinNoiseManager(QWidget* parent = nullptr);
    Grid<int> generate() override;
  public slots:
    void onUseSeedCheckboxStateChanged(int state);
};