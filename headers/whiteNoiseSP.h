#pragma once
#include "headers/generator.h"
#include <QGroupBox>
#include <QSpinBox>

// // consider using this class (as a parent for algorithmSPs)
// // when there is a need to store a pointer to an object that has both properties of QGroupBox and Generator.
// // for now, since I am only interested in the generate() method, I will store a pointer to Generator...
// // ? but a generator of int or floats???
// class AlgorithmSettingsPanel : public QGroupBox, public Generator<int>
// {
//   public:
//     AlgorithmSettingsPanel(QWidget* parent) : QGroupBox{parent} {};
// };

// this name might be misleading, since apart from being the settings panel for white noise this object is also
// the one responsible for calling the generate function
// might change this later, idk
class WhiteNoiseSettingsPanel : public QGroupBox, public Generator
{
  private:
    QSpinBox* widthSpinbox;
    QSpinBox* heightSpinbox;
    QSpinBox* percentSpinbox;

  public:
    WhiteNoiseSettingsPanel(QWidget* parent = nullptr);
    Grid<int> generate() override;
};