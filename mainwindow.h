#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QWidget *centralWidget;
    QGridLayout* gridLayout;

public:
    MainWindow(QWidget *parent = 0);
};

#endif // MAINWINDOW_H
