#include "headers/settingsPanel.h"
#include "alg/headers/algorithms.h"
#include "headers/CAManager.h"
#include "headers/config.h"
#include "headers/imageGenerator.h"
#include "headers/openSimplex2FManager.h"
#include "headers/perlinManager.h"
#include "headers/whiteNoiseManager.h"

#include <QFileDialog>
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

    PerlinNoiseManager* perlinManager = new PerlinNoiseManager(this);
    dropdownIndexToAlgManPtr[config::ALG_NAME_PERLIN_NOISE] = perlinManager;
    perlinManager->setVisible(false);

    OpenSimplex2FManager* openSimplex2FManager = new OpenSimplex2FManager(this);
    dropdownIndexToAlgManPtr[config::ALG_NAME_OPEN_SIMPLEX_2F] = openSimplex2FManager;
    openSimplex2FManager->setVisible(false);

    // Create settings panel components
    dropdown = new QComboBox(this);
    QObject::connect(dropdown, SIGNAL(currentTextChanged(const QString&)), this, SLOT(selectAlgorithm(const QString&)));
    // these names MUST match those in map
    dropdown->addItem(config::ALG_NAME_WHITE_NOISE);
    dropdown->addItem(config::ALG_NAME_CELLULAR_AUTOMATA);
    dropdown->addItem(config::ALG_NAME_PERLIN_NOISE);
    dropdown->addItem(config::ALG_NAME_OPEN_SIMPLEX_2F);

    QPushButton* generateButton = new QPushButton(config::GENERATE_BUTTON_TEXT);
    QPushButton* saveButton = new QPushButton(config::SAVE_BUTTON_TEXT);
    QObject::connect(generateButton, SIGNAL(clicked()), this, SLOT(onGenerateButtonClicked()));
    QObject::connect(saveButton, SIGNAL(clicked()), this, SLOT(onSaveButtonClicked()));

    // Install a layout and add items to it.
    QVBoxLayout* settingsLayout = new QVBoxLayout(this);
    settingsLayout->addWidget(dropdown);
    settingsLayout->addWidget(whiteNoiseManager);
    settingsLayout->addWidget(CAmanager);
    settingsLayout->addWidget(perlinManager);
    settingsLayout->addWidget(openSimplex2FManager);
    settingsLayout->addStretch();
    settingsLayout->addWidget(saveButton);
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
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    QStringList fileNames;
    if (fileDialog.exec())
        fileNames = fileDialog.selectedFiles();
    emit requestPreviewImageSave(fileNames[0]);
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