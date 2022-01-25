#include "headers/whiteNoiseManager.h"
#include "alg/headers/whiteNoise.h"
#include "headers/config.h"
#include <QFormLayout>

WhiteNoiseManager::WhiteNoiseManager(QWidget* parent) : AlgorithmManager{parent}
{
    QFormLayout* formLayout = new QFormLayout(this);
    formLayout->setSpacing(0);

    widthSpinbox = new QSpinBox{this};
    widthSpinbox->setValue(config::DEAFULT_IMAGE_WIDTH);
    widthSpinbox->setRange(config::MIN_IMAGE_SIZE, config::MAX_IMAGE_SIZE);

    heightSpinbox = new QSpinBox{this};
    heightSpinbox->setValue(config::DEFAULT_PREVIEW_HEIGHT);
    heightSpinbox->setRange(config::MIN_IMAGE_SIZE, config::MAX_IMAGE_SIZE);

    percentSpinbox = new QSpinBox(this);
    percentSpinbox->setValue(50); // magic number?
    percentSpinbox->setRange(0, 100);

    formLayout->addRow("width", widthSpinbox);
    formLayout->addRow("height", heightSpinbox);
    formLayout->addRow("white fill %", percentSpinbox);

    // formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow); // might want to consider this
    formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    formLayout->setLabelAlignment(Qt::AlignLeft);
}

Grid<int> WhiteNoiseManager::generate()
{
    return whiteNoise(widthSpinbox->value(), heightSpinbox->value(), percentSpinbox->value());
}
