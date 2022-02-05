#pragma once
#include "headers/algorithmManager.h"
#include <QCheckBox>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QSpinBox>

class OpenSimplex2FManager : public AlgorithmManager
{
  private:
    QFormLayout* formLayout;
    QSpinBox* widthSpinbox;
    QSpinBox* heightSpinbox;
    QSpinBox* offsetXSpinbox;
    QSpinBox* offsetYSpinbox;
    QDoubleSpinBox* periodSpinbox;

  public:
    OpenSimplex2FManager(QWidget* parent = nullptr);
    Grid<int> generate() override;
};