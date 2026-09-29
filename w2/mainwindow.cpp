#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->slider->setMinimum(0);
    ui->slider->setMaximum(10);
    ui->slider->setValue(0);

    connect(ui->slider, &QSlider::valueChanged,
            this, &MainWindow::updateDisplay);

    connect(ui->plusButton, &QPushButton::clicked,
            this, [this]() {
                int value = ui->slider->value();

                if (value == 10)
                    value = 0;
                else
                    value++;

                ui->slider->setValue(value);
            });

    connect(ui->minusButton, &QPushButton::clicked,
            this, [this]() {
                int value = ui->slider->value();

                if (value == 0)
                    value = 10;
                else
                    value--;

                ui->slider->setValue(value);
            });

    updateDisplay(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDisplay(int value)
{
    QStringList words = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten"
    };

    ui->numberLabel->setText(QString::number(value));
    ui->wordLabel->setText(words[value]);
}