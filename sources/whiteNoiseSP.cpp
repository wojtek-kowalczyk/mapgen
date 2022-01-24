#include "headers/whiteNoiseSP.h"
#include <QFormLayout>
#include <cstdlib>
#include <ctime>

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
    int width = widthSpinbox->value();
    int height = heightSpinbox->value();
    srand(time(nullptr));
    Grid<int> grid{width, height};
    for (int i = 0; i < grid.width; i++)
    {
        for (int j = 0; j < grid.height; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }
    return grid;
}
