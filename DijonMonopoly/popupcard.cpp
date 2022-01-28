#include "popupcard.h"

PopUpCard::PopUpCard(QWidget *parent): QMainWindow(parent)
{
    this->setWindowTitle("Cartes de jeu");
    this->setGeometry(650,300,519,276);
    this->setFixedSize(this->size());
    this->initComponent();
    this->initLayout();
}

void PopUpCard::initComponent() {
    this->centre = new QWidget();
    this->button = new QPushButton("OK");
    this->label = new QLabel();
    //this->image = new QImage();
}

void PopUpCard::initLayout() {
    this->setCentralWidget(this->centre);
    this->formLayout = new QFormLayout();
    /* this->image = new QImage();
    image->load("file:///Z:/Documents/Monopoly/DijMonopoly/Cases/Imagepopupcartes.png");
    */
// image->load("Z:\Documents\Monopoly\DijMonopoly\Cases\Imagepopupcartes.png");
    this->label = new QLabel("YO SLP DE DESF");
    this->formLayout->addWidget(this->button);
}
