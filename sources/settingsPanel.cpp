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
    activeAlgorithmManager = nullptr;

    // temp
    WhiteNoiseManager* temp1 = new WhiteNoiseManager(this);
    WhiteNoiseManager* temp2 = new WhiteNoiseManager(this);
    WhiteNoiseManager* temp3 = new WhiteNoiseManager(this);
    temp1->widthSpinbox->setValue(1);
    temp2->widthSpinbox->setValue(2);
    temp3->widthSpinbox->setValue(3);

    dropdown = new QComboBox(this);
    QObject::connect(dropdown, SIGNAL(currentTextChanged(const QString&)), this, SLOT(selectAlgorithm(const QString&)));
    dropdown->addItem("Dummy Algorithm (not implemented)");
    dropdown->addItem("temp1");
    dropdown->addItem("temp2");
    dropdown->addItem("temp3");

    dropdownIndexToAlgManPtr["temp1"] = temp1;
    dropdownIndexToAlgManPtr["temp2"] = temp2;
    dropdownIndexToAlgManPtr["temp3"] = temp3;

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
    if (activeAlgorithmManager)
    {
        Grid<int> grid = activeAlgorithmManager->generate();
        QImage* img = new QImage{dataToImage(grid, grid.width, grid.height)};
        emit requestPreviewImageChange(img);
    }
}

void SettingsPanel::onSaveButtonClicked()
{
}

#include <iostream>
void SettingsPanel::selectAlgorithm(const QString& key)
{
    try
    {
        AlgorithmManager* selected = dropdownIndexToAlgManPtr.at(key);
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
        std::cout << "no algorithm manager found for key: " << key.toStdString() << '\n';
    }
}