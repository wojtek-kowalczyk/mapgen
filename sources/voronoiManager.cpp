#include "headers/voronoiManager.h"
#include "alg/headers/algorithms.h"
#include "headers/config.h"
#include <QFormLayout>

VoronoiManager::VoronoiManager(QWidget* parent) : AlgorithmManager{parent}
{
    formLayout = new QFormLayout(this);
    formLayout->setSpacing(10);

    widthSpinbox = new QSpinBox{this};
    widthSpinbox->setRange(config::MIN_IMAGE_SIZE, config::MAX_IMAGE_SIZE);
    widthSpinbox->setValue(config::DEAFULT_IMAGE_WIDTH_MEDIUM);

    heightSpinbox = new QSpinBox{this};
    heightSpinbox->setRange(config::MIN_IMAGE_SIZE, config::MAX_IMAGE_SIZE);
    heightSpinbox->setValue(config::DEAFULT_IMAGE_HEIGHT_MEDIUM);

    pointsSpinbox = new QSpinBox(this);
    pointsSpinbox->setRange(1, 2000);
    pointsSpinbox->setValue(25);

    seedSpinbox = new QSpinBox{this};
    seedSpinbox->setRange(0, std::numeric_limits<int>::max());
    seedSpinbox->setValue(rand());
    seedSpinbox->setVisible(false); // start with this disabled

    exponentSpinbox = new QDoubleSpinBox{this};
    exponentSpinbox->setRange(0.1, 10);
    exponentSpinbox->setValue(2);

    useRandomSeedCheckbox = new QCheckBox(this);
    useRandomSeedCheckbox->setChecked(true);
    QObject::connect(useRandomSeedCheckbox, SIGNAL(stateChanged(int)), this,
                     SLOT(onUseRandomSeedCheckboxStateChanged(int)));

    formLayout->addRow("width", widthSpinbox);
    formLayout->addRow("height", heightSpinbox);
    formLayout->addRow("number of points", pointsSpinbox);
    formLayout->addRow("exponent", exponentSpinbox);
    formLayout->addRow("use random seed", useRandomSeedCheckbox);
    formLayout->addRow("seed", seedSpinbox);
    formLayout->labelForField(seedSpinbox)->setVisible(false); // start with this disabled

    formLayout->labelForField(widthSpinbox)->setToolTip("width of the raw image. preview is scaled");
    formLayout->labelForField(heightSpinbox)->setToolTip("height of the raw image. preview is scaled");
    formLayout->labelForField(pointsSpinbox)
        ->setToolTip("number of points used int the algorithm. equivalent to number of cells");
    formLayout->labelForField(exponentSpinbox)
        ->setToolTip("The exponent p in Minkowsky's distance function. Set this to 2 for euclidean distance");
    formLayout->labelForField(useRandomSeedCheckbox)
        ->setToolTip("if true, seed will be randomized for each generation");
    formLayout->labelForField(seedSpinbox)->setToolTip("the seed for random generator");

    formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    formLayout->setLabelAlignment(Qt::AlignLeft);
}

Grid<int> VoronoiManager::generate()
{
    if (useRandomSeedCheckbox->isChecked())
    {
        static int calls = 0;
        return voronoi(widthSpinbox->value(), heightSpinbox->value(), pointsSpinbox->value(), exponentSpinbox->value(),
                       time(nullptr) + (++calls));
    }
    else
    {
        return voronoi(widthSpinbox->value(), heightSpinbox->value(), pointsSpinbox->value(), exponentSpinbox->value(),
                       seedSpinbox->value());
    }
}

void VoronoiManager::onUseRandomSeedCheckboxStateChanged(int state)
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