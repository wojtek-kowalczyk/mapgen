#include "headers/whiteNoiseSP.h"
#include "alg/headers/whiteNoise.h"
#include "headers/config.h"
#include <QFormLayout>

WhiteNoiseSettingsPanel::WhiteNoiseSettingsPanel(QWidget* parent) : QGroupBox{parent}
{
    QFormLayout* formLayout = new QFormLayout(this);
    formLayout->setSpacing(0);

    widthSpinbox = new QSpinBox{this};
    widthSpinbox->setValue(50);
    widthSpinbox->setRange(config::MIN_IMAGE_SIZE, config::MAX_IAMGE_SIZE);

    heightSpinbox = new QSpinBox{this};
    heightSpinbox->setValue(50);
    heightSpinbox->setRange(config::MIN_IMAGE_SIZE, config::MAX_IAMGE_SIZE);

    percentSpinbox = new QSpinBox(this);
    percentSpinbox->setValue(50);
    percentSpinbox->setRange(0, 100);

    formLayout->addRow("width", widthSpinbox);
    formLayout->addRow("height", heightSpinbox);
    formLayout->addRow("white fill %", percentSpinbox);

    // formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow); // might want to consider this
    formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    formLayout->setLabelAlignment(Qt::AlignLeft);
}

Grid<int> WhiteNoiseSettingsPanel::generate()
{
    return whiteNoise(widthSpinbox->value(), heightSpinbox->value(), percentSpinbox->value());
}
