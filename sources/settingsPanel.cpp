#include "headers/settingsPanel.h"
#include "headers/config.h"

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

    // temp - this should be replaced by algorithm specific class deriving from QGroupBox
    QGroupBox* tempGroupBox = new QGroupBox{"Algorithm settings"};
    QVBoxLayout* tempBoxLayout = new QVBoxLayout(tempGroupBox);
    tempBoxLayout->addStretch();

    settingsLayout->addWidget(label1);
    settingsLayout->addWidget(label2);
    settingsLayout->addWidget(label3);
    settingsLayout->addWidget(dropdown);
    settingsLayout->addWidget(tempGroupBox);
    settingsLayout->addStretch();
    settingsLayout->addWidget(generateButton);
}

void SettingsPanel::onGenerateButtonClicked()
{
}

void SettingsPanel::onSaveButtonClicked()
{
}