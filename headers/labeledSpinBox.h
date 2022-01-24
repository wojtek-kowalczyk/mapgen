
// * UNUSED - I FOUND OUT ABOUT QFormLayout

#pragma once
#include <QLabel>
#include <QSpinBox>
#include <QWidget>

// a wraper to place lebel to the (left) side of spinbox.
class LabeledSpinBox : public QWidget
{
  public:
    LabeledSpinBox(const char* labelText, QWidget* parent = nullptr);
    QSpinBox* spinBox;
    QLabel* label;
};
