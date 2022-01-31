#include "popuppayrent.h"

PopUpPayRent::PopUpPayRent(Case* e, class Player* buyer)
{
    this->ownerName = e->getOwner()->getName();
    this->buyerName = buyer->getName();
    this->price = e->getRent();
    this->initComponents();
    this->initLayout();
    this->initSlots();
}

void PopUpPayRent::initComponents() {
    this->centre = new QWidget();
    this->label = new QLabel(QString::fromStdString(this->buyerName + " est sur une propriété de "+ this->ownerName + ", il doit payer "+ std::to_string(this->price)));
    this->okBtn = new QPushButton("Payer");
}

void PopUpPayRent::initLayout() {
    std::cout << "initLayout" << std::endl;
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
