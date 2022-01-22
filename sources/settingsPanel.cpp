#include "headers/settingsPanel.h"
#include "headers/config.h"

#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

SettingsPanel::SettingsPanel(QWidget* parent) : QGroupBox{"Settings", parent}
{
    setFixedWidth(config::SETTINGS_PANEL_WIDTH);
    QVBoxLayout* settingsLayout = new QVBoxLayout(this);

    // Items
    QComboBox* dropdown = new QComboBox();
    dropdown->addItem("Algorithm 1");
    dropdown->addItem("Algorithm 2");
    dropdown->addItem("Algorithm 3");
    QLabel* label1 = new QLabel("Label 1");
    QLabel* label2 = new QLabel("Label 2");
    QLabel* label3 = new QLabel("Label 3");
    label1->setStyleSheet("background-color: grey");
    QPushButton* generateButton = new QPushButton("Generate");
    QObject::connect(generateButton, SIGNAL(clicked()), this, SLOT(tmp_buttonClick()));

    settingsLayout->addWidget(label1);
    settingsLayout->addWidget(label2);
    settingsLayout->addWidget(label3);
    settingsLayout->addWidget(dropdown);
    settingsLayout->addStretch();
    settingsLayout->addWidget(generateButton);
}

// temp - remove later
#include <iostream>
void SettingsPanel::tmp_buttonClick()
{
    std::cout << "button was clicked\n";
}