#include "headers/whiteNoiseManager.h"
#include "alg/headers/algorithms.h"
#include "headers/config.h"
#include <QFormLayout>
#include <QLabel>

WhiteNoiseManager::WhiteNoiseManager(QWidget* parent) : AlgorithmManager{parent}
{
    QFormLayout* formLayout = new QFormLayout(this);
    formLayout->setSpacing(0);

    widthSpinbox = new QSpinBox{this};
    widthSpinbox->setRange(config::MIN_IMAGE_SIZE, config::MAX_IMAGE_SIZE);
    widthSpinbox->setValue(config::DEAFULT_IMAGE_WIDTH_SMALL);

    heightSpinbox = new QSpinBox{this};
    heightSpinbox->setRange(config::MIN_IMAGE_SIZE, config::MAX_IMAGE_SIZE);
    heightSpinbox->setValue(config::DEAFULT_IMAGE_HEIGHT_SMALL);

    percentSpinbox = new QSpinBox(this);
    percentSpinbox->setRange(0, 100);
    percentSpinbox->setValue(config::DEFAULT_FILL_PERCENT);

    formLayout->addRow("width", widthSpinbox);
    formLayout->addRow("height", heightSpinbox);
    formLayout->addRow("white %", percentSpinbox);
    formLayout->labelForField(widthSpinbox)->setToolTip("width of the raw image. preview is scaled");
    formLayout->labelForField(heightSpinbox)->setToolTip("height of the raw image. preview is scaled");
    formLayout->labelForField(percentSpinbox)->setToolTip("what % of image is made of white pixels, roughly");

    // formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow); // might want to consider this
    formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    formLayout->setLabelAlignment(Qt::AlignLeft);
}

Grid<int> WhiteNoiseManager::generate()
{
    return whiteNoise(widthSpinbox->value(), heightSpinbox->value(), percentSpinbox->value());
}
