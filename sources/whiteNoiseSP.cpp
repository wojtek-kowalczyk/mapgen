#include "headers/whiteNoiseSP.h"
#include "alg/headers/whiteNoise.h"
#include <QFormLayout>

WhiteNoiseSettingsPanel::WhiteNoiseSettingsPanel(QWidget* parent) : QGroupBox{parent}
{
    QFormLayout* formLayout = new QFormLayout(this);
    formLayout->setSpacing(0);

    widthSpinbox = new QSpinBox{this};
    widthSpinbox->setValue(50);
    widthSpinbox->setRange(1, 16'348);

    heightSpinbox = new QSpinBox{this};
    heightSpinbox->setValue(50);
    heightSpinbox->setRange(1, 16'348);

    formLayout->addRow("width", widthSpinbox);
    formLayout->addRow("height", heightSpinbox);

    // formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow); // might want to consder this
    formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    formLayout->setLabelAlignment(Qt::AlignLeft);
}

Grid<int> WhiteNoiseSettingsPanel::generate()
{
    return whiteNoise(widthSpinbox->value(), heightSpinbox->value());
}
