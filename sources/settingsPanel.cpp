#include "headers/settingsPanel.h"
#include "headers/config.h"
#include "headers/imageGenerator.h"
#include "headers/whiteNoiseSP.h"
#include <QLabel>
#include <QVBoxLayout>

SettingsPanel::SettingsPanel(QWidget* parent) : QGroupBox{"Settings", parent}
{
    setFixedWidth(config::SETTINGS_PANEL_WIDTH);
    QVBoxLayout* settingsLayout = new QVBoxLayout(this);

    // Items
    dropdown = new QComboBox();
    dropdown->addItem("Algorithm 1");
    dropdown->addItem("Algorithm 2");
    dropdown->addItem("Algorithm 3");
    QLabel* label1 = new QLabel("Label 1");
    QLabel* label2 = new QLabel("Label 2");
    QLabel* label3 = new QLabel("Label 3");
    label1->setStyleSheet("background-color: grey");
    QPushButton* generateButton = new QPushButton("Generate");
    QObject::connect(generateButton, SIGNAL(clicked()), this, SLOT(onGenerateButtonClicked()));

    WhiteNoiseSettingsPanel* whiteNoiseSP = new WhiteNoiseSettingsPanel{this};

    settingsLayout->addWidget(label1);
    settingsLayout->addWidget(label2);
    settingsLayout->addWidget(label3);
    settingsLayout->addWidget(dropdown);
    settingsLayout->addWidget(whiteNoiseSP);
    settingsLayout->addStretch();
    settingsLayout->addWidget(generateButton);
}

void SettingsPanel::onGenerateButtonClicked()
{
}

void SettingsPanel::onSaveButtonClicked()
{
}