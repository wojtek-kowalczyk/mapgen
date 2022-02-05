#include "headers/whiteNoiseManager.h"
#include "alg/headers/algorithms.h"
#include "headers/config.h"
#include <QLabel>
#include <ctime>

WhiteNoiseManager::WhiteNoiseManager(QWidget* parent) : AlgorithmManager{parent}
{
    formLayout = new QFormLayout(this);
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

    seedSpinbox = new QSpinBox{this};
    seedSpinbox->setRange(0, std::numeric_limits<int>::max());
    seedSpinbox->setValue(rand());
    seedSpinbox->setVisible(false); // start with this disabled

    useRandomSeedCheckbox = new QCheckBox(this);
    useRandomSeedCheckbox->setChecked(true);
    QObject::connect(useRandomSeedCheckbox, SIGNAL(stateChanged(int)), this,
                     SLOT(onUseRandomSeedCheckboxStateChanged(int)));

    formLayout->addRow("width", widthSpinbox);
    formLayout->addRow("height", heightSpinbox);
    formLayout->addRow("white %", percentSpinbox);
    formLayout->addRow("use random seed", useRandomSeedCheckbox);
    formLayout->addRow("seed", seedSpinbox);
    formLayout->labelForField(seedSpinbox)->setVisible(false); // initially hidden

    formLayout->labelForField(widthSpinbox)->setToolTip("width of the raw image. preview is scaled");
    formLayout->labelForField(heightSpinbox)->setToolTip("height of the raw image. preview is scaled");
    formLayout->labelForField(percentSpinbox)->setToolTip("what % of image is made of white pixels, roughly");
    formLayout->labelForField(useRandomSeedCheckbox)
        ->setToolTip("If checked, the seed will be randomized for each generation");
    formLayout->labelForField(seedSpinbox)->setToolTip("seed for random number generator");

    // formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow); // might want to consider this
    formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    formLayout->setLabelAlignment(Qt::AlignLeft);
}

Grid<int> WhiteNoiseManager::generate()
{
    if (useRandomSeedCheckbox->isChecked())
    {
        static int calls{0};
        return whiteNoise(widthSpinbox->value(), heightSpinbox->value(), percentSpinbox->value(),
                          time(nullptr) + (++calls));
    }
    else
    {
        return whiteNoise(widthSpinbox->value(), heightSpinbox->value(), percentSpinbox->value(), seedSpinbox->value());
    }
}

void WhiteNoiseManager::onUseRandomSeedCheckboxStateChanged(int state)
{
    if (state == Qt::Unchecked)
    {
        seedSpinbox->setVisible(true);
        formLayout->labelForField(seedSpinbox)->setVisible(true);
    }
    else
    {
        seedSpinbox->setVisible(false);
        formLayout->labelForField(seedSpinbox)->setVisible(false);
    }
}