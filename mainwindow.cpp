#include "mainwindow.h"
#include "timerlabel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    gridLayout = new QGridLayout(centralWidget);

    gridLayout->addWidget(new TimerLabel(centralWidget), 0, 0);
    gridLayout->addWidget(new TimerLabel(centralWidget), 1, 0);
    gridLayout->addWidget(new TimerLabel(centralWidget), 2, 0);

    gridLayout->addWidget(new TimerLabel(centralWidget), 0, 1);
    gridLayout->addWidget(new TimerLabel(centralWidget), 1, 1);
    gridLayout->addWidget(new TimerLabel(centralWidget), 2, 1);

    gridLayout->addWidget(new TimerLabel(centralWidget), 0, 2);
    gridLayout->addWidget(new TimerLabel(centralWidget), 1, 2);
    gridLayout->addWidget(new TimerLabel(centralWidget), 2, 2);
}
