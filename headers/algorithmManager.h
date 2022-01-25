#pragma once
#include "headers/generator.h"
#include <QGroupBox>

// I'm still not convinced whether combining GUI component with Generator is a good idea
// todo - Might wanna re-think this

class AlgorithmManager : public QGroupBox, public Generator
{
  public:
    AlgorithmManager(QWidget* parent) : QGroupBox{parent} {};
};
