#include "headers/openSimplex2FManager.h"
#include "headers/config.h"
#include <QFormLayout>
#include <limits>

extern "C"
{
#include "alg/headers/openSimplex2F.h"
}

OpenSimplex2FManager::OpenSimplex2FManager(QWidget* parent) : AlgorithmManager{parent}
{
    formLayout = new QFormLayout(this);
    formLayout->setSpacing(0);

    widthSpinbox = new QSpinBox{this};
    widthSpinbox->setRange(config::MIN_IMAGE_SIZE, config::MAX_IMAGE_SIZE);
    widthSpinbox->setValue(config::DEAFULT_IMAGE_WIDTH_MEDIUM);

    heightSpinbox = new QSpinBox{this};
    heightSpinbox->setRange(config::MIN_IMAGE_SIZE, config::MAX_IMAGE_SIZE);
    heightSpinbox->setValue(config::DEAFULT_IMAGE_HEIGHT_MEDIUM);

    offsetXSpinbox = new QSpinBox{this};
    offsetXSpinbox->setRange(std::numeric_limits<int>::min() + config::MAX_IMAGE_SIZE + 1,
                             std::numeric_limits<int>::max() - config::MAX_IMAGE_SIZE - 1);
    offsetXSpinbox->setValue(0);

    offsetYSpinbox = new QSpinBox{this};
    offsetYSpinbox->setRange(std::numeric_limits<int>::min() + config::MAX_IMAGE_SIZE + 1,
                             std::numeric_limits<int>::max() - config::MAX_IMAGE_SIZE - 1);
    offsetYSpinbox->setValue(0);

    periodSpinbox = new QDoubleSpinBox{this};
    periodSpinbox->setRange(1.0, 10'000.0);
    periodSpinbox->setValue(100.0);

    formLayout->addRow("width", widthSpinbox);
    formLayout->addRow("height", heightSpinbox);
    formLayout->addRow("offset X", offsetXSpinbox);
    formLayout->addRow("offset Y", offsetYSpinbox);
    formLayout->addRow("zoom", periodSpinbox);

    formLayout->labelForField(widthSpinbox)->setToolTip("width of the raw image. preview is scaled");
    formLayout->labelForField(heightSpinbox)->setToolTip("height of the raw image. preview is scaled");
    formLayout->labelForField(offsetXSpinbox)->setToolTip("move map on X axis");
    formLayout->labelForField(offsetYSpinbox)->setToolTip("move map on Y axis");
    formLayout->labelForField(periodSpinbox)
        ->setToolTip("zoom in on the map. This value is in fact period, from which 1/period is used in computation");

    formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    formLayout->setLabelAlignment(Qt::AlignLeft);
}

// helper - maps the value in range [a,b] to a value in range [A,B], linearly
inline double map(double val, double a, double b, double A, double B)
{
    return (A + ((B - A) / (b - a)) * (val - a));
}

Grid<int> OpenSimplex2FManager::generate()
{
    OpenSimplexEnv* ose = initOpenSimplex();
    OpenSimplexGradients* osg = newOpenSimplexGradients(ose, 1234);

    Grid<int> pixelData{widthSpinbox->value(), heightSpinbox->value()};
    double freq{};
    for (int y = 0; y < pixelData.height; y++)
    {
        for (int x = 0; x < pixelData.width; x++)
        {
            freq = 1 / periodSpinbox->value();
            pixelData[y][x] = static_cast<int>(
                map(noise2(ose, osg, (x + offsetXSpinbox->value()) * freq, (y + offsetYSpinbox->value()) * freq), -1, 1,
                    0, 255));
        }
    }
    return pixelData;
}
