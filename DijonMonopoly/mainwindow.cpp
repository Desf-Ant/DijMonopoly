#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    this->setWindowTitle("Dij'Monop");
    this->setGeometry(0,0,1000,1000);
    this->initComponents();
    this->initLayout();
}

MainWindow::~MainWindow()
{

}


void MainWindow::initComponents() {
    this->centre = new QWidget();
    this->board = new QRect(10,10,100,100);
}

void MainWindow::initLayout() {
    this->setCentralWidget(this->centre);
    this->vbox = new QVBoxLayout();
    this->centre->setLayout(this->vbox);
}
