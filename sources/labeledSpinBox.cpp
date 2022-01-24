
// * UNUSED - I FOUND OUT ABOUT QFormLayout

#include "headers/labeledSpinBox.h"
#include <QHBoxLayout>
LabeledSpinBox::LabeledSpinBox(const char* labelText, QWidget* parent) : QWidget{parent}
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    // setLayout(new QHBoxLayout()); // ? is this the same memory/parent-wise? (I think so)

    spinBox = new QSpinBox();
    label = new QLabel(labelText);
}