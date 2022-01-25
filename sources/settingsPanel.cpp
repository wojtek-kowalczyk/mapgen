#include "headers/settingsPanel.h"
#include "headers/config.h"
#include "headers/imageGenerator.h"
#include "headers/whiteNoiseManager.h"
#include <QLabel>
#include <QVBoxLayout>

SettingsPanel::SettingsPanel(QWidget* parent) : QGroupBox{"Settings", parent}
{
    setFixedWidth(config::SETTINGS_PANEL_WIDTH);
    QVBoxLayout* settingsLayout = new QVBoxLayout(this);

    // temp
    WhiteNoiseManager* temp1 = new WhiteNoiseManager(this);
    WhiteNoiseManager* temp2 = new WhiteNoiseManager(this);
    WhiteNoiseManager* temp3 = new WhiteNoiseManager(this);
    temp1->widthSpinbox->setValue(1);
    temp2->widthSpinbox->setValue(2);
    temp3->widthSpinbox->setValue(3);

    dropdown = new QComboBox(this);
    QObject::connect(dropdown, SIGNAL(currentIndexChanged(int)), this, SLOT(selectAlgorithm(int)));
    dropdown->addItem("Dummy Algorithm (not implemented)");
    dropdown->addItem("temp1");
    dropdown->addItem("temp2");
    dropdown->addItem("temp3");
    // todo - start from here - rethink this, maybe come up with another solution
    // order is important, this seems sketchy. I DON'T LIKE IT
    // Do I trust that indexes will be 0,1,2,3,4... or maybe pass some int wrapped in QVariant as data??
    // At this moment, I'm creating all the algmanagers, adding them to layout, setting to be invisible,
    // and adding them to a map with respective int (dropdwon index) as a key. Then when user changes the selected alg
    // i query the map to give me pointer to the right object and set this object to visible, and make it activeManager
    dropdownIndexToAlgManPtr[1] = temp1;
    dropdownIndexToAlgManPtr[2] = temp2;
    dropdownIndexToAlgManPtr[3] = temp3;

    QPushButton* generateButton = new QPushButton(config::GENERATE_BUTTON_TEXT);
    QObject::connect(generateButton, SIGNAL(clicked()), this, SLOT(onGenerateButtonClicked()));

    settingsLayout->addWidget(dropdown);
    settingsLayout->addWidget(temp1);
    settingsLayout->addWidget(temp2);
    settingsLayout->addWidget(temp3);
    temp1->setVisible(false);
    temp2->setVisible(false);
    temp3->setVisible(false);
    settingsLayout->addStretch();
    settingsLayout->addWidget(generateButton);
}

void SettingsPanel::onGenerateButtonClicked()
{
    Grid<int> grid = activeAlgorithmManager->generate();
    QImage* img = new QImage{dataToImage(grid, grid.width, grid.height)};
    emit requestPreviewImageChange(img);
}

void SettingsPanel::onSaveButtonClicked()
{
}

#include <iostream>
void SettingsPanel::selectAlgorithm(int idx)
{
    // I need my custom type, but it seems like too much fuss
    // QWidget* selected = dropdown->currentData().value<QWidget*>();
    try
    {
        AlgorithmManager* selected = dropdownIndexToAlgManPtr.at(idx);
        std::cout << "got: " << selected << '\n';
        if (selected)
        {
            if (activeAlgorithmManager)
                activeAlgorithmManager->setVisible(false);
            activeAlgorithmManager = selected;
            activeAlgorithmManager->setVisible(true);
        }
        else
        {
            std::cout << "nullptr\n";
        }
    }
    catch (std::out_of_range& e)
    {
        std::cout << "no algorithm manager found for index: " << idx << '\n';
    }
}