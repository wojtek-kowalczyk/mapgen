#include "headers/settingsPanel.h"
#include "headers/CAManager.h"
#include "headers/config.h"
#include "headers/imageGenerator.h"
#include "headers/whiteNoiseManager.h"
#include <QLabel>
#include <QVBoxLayout>

SettingsPanel::SettingsPanel(QWidget* parent) : QGroupBox{"Settings", parent}
{
    // Initial setup
    setFixedWidth(config::SETTINGS_PANEL_WIDTH);
    activeAlgorithmManager = nullptr;

    // Create Algorithm Managers
    WhiteNoiseManager* whiteNoiseManager = new WhiteNoiseManager(this);
    dropdownIndexToAlgManPtr[config::ALG_NAME_WHITE_NOISE] = whiteNoiseManager;
    whiteNoiseManager->setVisible(false);

    CellularAutomataManager* CAmanager = new CellularAutomataManager(this);
    dropdownIndexToAlgManPtr[config::ALG_NAME_CELLULAR_AUTOMATA] = CAmanager;
    CAmanager->setVisible(false);

    // Create settings panel components
    dropdown = new QComboBox(this);
    QObject::connect(dropdown, SIGNAL(currentTextChanged(const QString&)), this, SLOT(selectAlgorithm(const QString&)));
    // these names MUST match those in map
    dropdown->addItem(config::ALG_NAME_WHITE_NOISE);
    dropdown->addItem(config::ALG_NAME_CELLULAR_AUTOMATA);

    QPushButton* generateButton = new QPushButton(config::GENERATE_BUTTON_TEXT);
    QPushButton* saveButton = new QPushButton(config::SAVE_BUTTON_TEXT);
    QObject::connect(generateButton, SIGNAL(clicked()), this, SLOT(onGenerateButtonClicked()));
    QObject::connect(saveButton, SIGNAL(clicked()), this, SLOT(onSaveButtonClicked()));
    saveButton->setEnabled(false); // ! temporary - enable when save functionality is added

    // Install a layout and add items to it.
    QVBoxLayout* settingsLayout = new QVBoxLayout(this);
    settingsLayout->addWidget(dropdown);
    settingsLayout->addWidget(whiteNoiseManager);
    settingsLayout->addWidget(CAmanager);
    // other algorithms go here
    settingsLayout->addStretch();
    settingsLayout->addWidget(saveButton);
    settingsLayout->addWidget(generateButton);
}

#include "alg/headers/algorithms.h"
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

void SettingsPanel::selectAlgorithm(const QString& key)
{
    // I'm not catching the possible std::out_of_range exception thrown by at()
    // because this should never happen, and if it does, I want to know about it.
    AlgorithmManager* selected = dropdownIndexToAlgManPtr.at(key);
    if (selected)
    {
        if (activeAlgorithmManager)
            activeAlgorithmManager->setVisible(false);
        activeAlgorithmManager = selected;
        activeAlgorithmManager->setVisible(true);
    }
}