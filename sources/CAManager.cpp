#include "headers/CAManager.h"
#include "alg/headers/algorithms.h"
#include "headers/config.h"
#include <ctime>

CellularAutomataManager::CellularAutomataManager(QWidget* parent) : AlgorithmManager{parent}
{
    formLayout = new QFormLayout(this);
    formLayout->setSpacing(10);

    widthSpinbox = new QSpinBox{this};
    widthSpinbox->setRange(config::MIN_IMAGE_SIZE, config::MAX_IMAGE_SIZE);
    widthSpinbox->setValue(config::DEAFULT_IMAGE_WIDTH_SMALL);

    heightSpinbox = new QSpinBox{this};
    heightSpinbox->setRange(config::MIN_IMAGE_SIZE, config::MAX_IMAGE_SIZE);
    heightSpinbox->setValue(config::DEAFULT_IMAGE_HEIGHT_SMALL);

    percentSpinbox = new QSpinBox(this);
    percentSpinbox->setRange(0, 100);
    percentSpinbox->setValue(50);

    neighborsRuleSpinBox = new QSpinBox(this);
    neighborsRuleSpinBox->setRange(0, 8);
    neighborsRuleSpinBox->setValue(4);

    iterationsSpinbox = new QSpinBox(this);
    iterationsSpinbox->setRange(1, 10);
    iterationsSpinbox->setValue(5);

    seedSpinbox = new QSpinBox{this};
    seedSpinbox->setRange(0, std::numeric_limits<int>::max());
    seedSpinbox->setValue(rand());
    seedSpinbox->setVisible(false); // start with this disabled

    tilingCheckBox = new QCheckBox(this);
    QObject::connect(tilingCheckBox, SIGNAL(stateChanged(int)), this, SLOT(onTilingCheckboxStateChange(int)));
    whiteBorderCheckBox = new QCheckBox(this);

    useRandomSeedCheckbox = new QCheckBox(this);
    useRandomSeedCheckbox->setChecked(true);
    QObject::connect(useRandomSeedCheckbox, SIGNAL(stateChanged(int)), this,
                     SLOT(onUseRandomSeedCheckboxStateChanged(int)));

    formLayout->addRow("width", widthSpinbox);
    formLayout->addRow("height", heightSpinbox);
    formLayout->addRow("white fill %", percentSpinbox);
    formLayout->addRow("neighbors Rule", neighborsRuleSpinBox);
    formLayout->addRow("iterations", iterationsSpinbox);
    formLayout->addRow("tiling", tilingCheckBox);
    formLayout->addRow("white border", whiteBorderCheckBox);
    formLayout->addRow("use random seed", useRandomSeedCheckbox);
    formLayout->addRow("seed", seedSpinbox);
    formLayout->labelForField(seedSpinbox)->setVisible(false); // initially hidden

    formLayout->labelForField(widthSpinbox)->setToolTip("width of the raw image. preview is scaled");
    formLayout->labelForField(heightSpinbox)->setToolTip("height of the raw image. preview is scaled");
    formLayout->labelForField(percentSpinbox)->setToolTip("what % of initial noise is made of white pixels, roughly");
    formLayout->labelForField(neighborsRuleSpinBox)
        ->setToolTip("How many pixels of given color have to be neighbors of a pixel, in order for this pixel to "
                     "become their color. Set this to 4 for \"become majority\"-type behaviour");
    formLayout->labelForField(iterationsSpinbox)->setToolTip("How many iteraions of the algorithm to apply");
    formLayout->labelForField(tilingCheckBox)->setToolTip("do you want the image to be tile-able. DISABLES BORDER");
    formLayout->labelForField(whiteBorderCheckBox)->setToolTip("What color do you want the border to be.");
    formLayout->labelForField(useRandomSeedCheckbox)
        ->setToolTip("if true, seed will be randomized for each generation");
    formLayout->labelForField(seedSpinbox)->setToolTip("the seed for random generator");

    // formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow); // might want to consider this
    formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    formLayout->setLabelAlignment(Qt::AlignLeft);
}

Grid<int> CellularAutomataManager::generate()
{
    if (useRandomSeedCheckbox->isChecked())
    {
        static int calls{0};
        return CellularAutomaton(widthSpinbox->value(), heightSpinbox->value(), percentSpinbox->value(),
                                 tilingCheckBox->isChecked(), whiteBorderCheckBox->isChecked(),
                                 iterationsSpinbox->value(), neighborsRuleSpinBox->value(), time(nullptr) + (++calls));
    }
    else
    {
        return CellularAutomaton(widthSpinbox->value(), heightSpinbox->value(), percentSpinbox->value(),
                                 tilingCheckBox->isChecked(), whiteBorderCheckBox->isChecked(),
                                 iterationsSpinbox->value(), neighborsRuleSpinBox->value(), seedSpinbox->value());
    }
}

void CellularAutomataManager::onTilingCheckboxStateChange(int state)
{
    // When Tiling is checked border has no effect, so hide it
    if (state == Qt::Checked)
    {
        whiteBorderCheckBox->setVisible(false);
        formLayout->labelForField(whiteBorderCheckBox)->setVisible(false);
    }
    else
    {
        whiteBorderCheckBox->setVisible(true);
        formLayout->labelForField(whiteBorderCheckBox)->setVisible(true);
    }
}

void CellularAutomataManager::onUseRandomSeedCheckboxStateChanged(int state)
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