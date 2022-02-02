#include "popuppayrent.h"

PopUpPayRent::PopUpPayRent(Case* e, class Player* buyer, int sumDice)
{
    this->ownerName = e->getOwner()->getName();
    this->buyerName = buyer->getName();
    this->price = e->getRent();
    this->caseName = e->getName();
    this->initComponents();
    this->initLayout();
    this->initSlots();
    this->sumDice = sumDice;
}

void PopUpPayRent::initComponents() {
    this->centre = new QWidget();
    if (this->sumDice > 0) {
        std::cout << this->price*this->sumDice << std::endl;
        this->label = new QLabel(QString::fromStdString(this->buyerName + " est sur " + this->caseName + " appartenant à "+ this->ownerName + ", il doit payer "+ std::to_string(this->price*this->sumDice)));
    }else
        this->label = new QLabel(QString::fromStdString(this->buyerName + " est sur " + this->caseName + " appartenant à "+ this->ownerName + ", il doit payer "+ std::to_string(this->price)));
    this->okBtn = new QPushButton("Payer");
}

void PopUpPayRent::initLayout() {
    this->setCentralWidget(this->centre);
    this->vbox = new QVBoxLayout();
    this->centre->setLayout(this->vbox);
    this->vbox->addWidget(this->label);
    this->vbox->addWidget(this->okBtn);
}

void PopUpPayRent::initSlots() {
    QWidget::connect(this->okBtn, SIGNAL(clicked()), this, SLOT(closeWindow()));
}

void PopUpPayRent::closeWindow() {
    this->close();
}
