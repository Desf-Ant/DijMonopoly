#include "mainwindow.h"

#include <iostream>
#include <QApplication>

#include "board.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.startMainWindow();
    return a.exec();
}
