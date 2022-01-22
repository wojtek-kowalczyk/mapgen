#include <QApplication>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char* argv[])
{
    QApplication app{argc, argv};

    QWidget* window = new QWidget();
    window->setBaseSize(512 + 256, 512);

    QLabel* previewLabel = new QLabel();
    QImage placeholder{"small.png"};
    previewLabel->setAlignment(Qt::AlignCenter);
    previewLabel->setPixmap(QPixmap::fromImage(placeholder).scaled(600, 600, Qt::KeepAspectRatio));

    QGroupBox* groupBox = new QGroupBox("Settings");
    groupBox->setFixedWidth(300);

    QVBoxLayout* settingsLayout = new QVBoxLayout(groupBox);
    QLabel* label1 = new QLabel("Label 1");
    QLabel* label2 = new QLabel("Label 2");
    QLabel* label3 = new QLabel("Label 3");
    label1->setStyleSheet("background-color: grey");
    settingsLayout->addWidget(label1);
    settingsLayout->addWidget(label2);
    settingsLayout->addWidget(label3);
    settingsLayout->addStretch();

    QHBoxLayout* windowLayout = new QHBoxLayout(window);
    windowLayout->addWidget(previewLabel);
    windowLayout->addWidget(groupBox);

    window->show();
    return app.exec();
}
