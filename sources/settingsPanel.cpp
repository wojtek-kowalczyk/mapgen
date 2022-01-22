#include "headers/settingsPanel.h"
#include <QLabel>
#include <QVBoxLayout>

SettingsPanel::SettingsPanel(QWidget* parent) : QGroupBox{"Settings", parent}
{
    setFixedWidth(300);
    QVBoxLayout* settingsLayout = new QVBoxLayout(this);
    // temp
    QLabel* label1 = new QLabel("Label 1");
    QLabel* label2 = new QLabel("Label 2");
    QLabel* label3 = new QLabel("Label 3");
    label1->setStyleSheet("background-color: grey");
    settingsLayout->addWidget(label1);
    settingsLayout->addWidget(label2);
    settingsLayout->addWidget(label3);
    // end temp
    settingsLayout->addStretch(); // add this to squish to top
}