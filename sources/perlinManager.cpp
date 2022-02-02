#include "headers/perlinManager.h"
#include "alg/headers/perlin.h"
#include "headers/config.h"
#include <QFormLayout>
#include <limits>

PerlinNoiseManager::PerlinNoiseManager(QWidget* parent) : AlgorithmManager{parent}
{
    formLayout = new QFormLayout(this);
    formLayout->setSpacing(0);

    widthSpinbox = new QSpinBox{this};
    widthSpinbox->setRange(config::MIN_IMAGE_SIZE, config::MAX_IMAGE_SIZE);
    widthSpinbox->setValue(config::DEAFULT_IMAGE_WIDTH_MEDIUM);

    heightSpinbox = new QSpinBox{this};
    heightSpinbox->setRange(config::MIN_IMAGE_SIZE, config::MAX_IMAGE_SIZE);
    heightSpinbox->setValue(config::DEAFULT_IMAGE_HEIGHT_MEDIUM);

    seedSpinbox = new QSpinBox{this};
    seedSpinbox->setRange(0, std::numeric_limits<int>::max());
    seedSpinbox->setValue(rand());
    seedSpinbox->setVisible(false); // start with it disabled

    scaleSpinBox = new QDoubleSpinBox(this);
    scaleSpinBox->setRange(1.0, 500.0);
    scaleSpinBox->setValue(75.0);

    useSeedCheckbox = new QCheckBox(this);
    QObject::connect(useSeedCheckbox, SIGNAL(stateChanged(int)), this, SLOT(onUseSeedCheckboxStateChanged(int)));

    formLayout->addRow("width", widthSpinbox);
    formLayout->addRow("height", heightSpinbox);
    formLayout->addRow("scale", scaleSpinBox);
    formLayout->addRow("use seed", useSeedCheckbox);
    formLayout->addRow("seed", seedSpinbox);

    formLayout->labelForField(widthSpinbox)->setToolTip("width of the raw image. preview is scaled");
    formLayout->labelForField(heightSpinbox)->setToolTip("height of the raw image. preview is scaled");
    formLayout->labelForField(scaleSpinBox)->setToolTip("Determines how \"zoomed in\" the image is");
    formLayout->labelForField(useSeedCheckbox)
        ->setToolTip("when checked uses the seed below to generate new permutations"
                     ", otherwise uses reference permutations");
    formLayout->labelForField(seedSpinbox)->setToolTip("seed to generate permutations.");
    formLayout->labelForField(seedSpinbox)->setVisible(false); // start with it disabled

    formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    formLayout->setLabelAlignment(Qt::AlignLeft);
}

Grid<int> PerlinNoiseManager::generate()
{
    PerlinNoise generator;
    if (useSeedCheckbox->isChecked())
        generator = PerlinNoise{static_cast<unsigned int>(abs(seedSpinbox->value()))};

    Grid<int> pixelValues{widthSpinbox->value(), heightSpinbox->value()};
    for (int i = 0; i < pixelValues.width; i++)
    {
        for (int j = 0; j < pixelValues.height; j++)
        {
            pixelValues[i][j] =
                static_cast<int>(generator.noise(i / scaleSpinBox->value(), j / scaleSpinBox->value(), 0) * 255);
        }
    }
    return pixelValues;
}

void PerlinNoiseManager::onUseSeedCheckboxStateChanged(int state)
{
    if (state == Qt::Checked)
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