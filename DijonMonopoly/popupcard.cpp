#include "popupcard.h"

PopUpCard::PopUpCard(QWidget *parent, typeDrawCard type): QMainWindow(parent)
{
    this->setWindowTitle("Cartes de jeu");
    this->setGeometry(650,300,519,276);
    this->setFixedSize(this->size());
    this->initComponent();
    this->initLayout();
    this->initSlots();

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
    this->centre->setLayout(this->formLayout);
    this->formLayout->addRow(this->label);
    DrawCard* dchance = new DrawCard();
    DrawCard* dcom = new DrawCard();
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    // std::cout << dchance->DrawChanceCard() << std::endl;
    if (typeDrawCard::ComCard) {
        label->setText (QString::fromStdString(dchance->DrawComCard()));
    }
    if (typeDrawCard::ChanceCard){
        label->setText (QString::fromStdString(dchance->DrawChanceCard()));
    }
    label->setAlignment(Qt::AlignBottom | Qt::AlignCenter);
    this->formLayout->addWidget(this->button);
}

void PopUpCard::initSlots() {
    QWidget::connect(this->button, SIGNAL(clicked()), this, SLOT(quit()));
}

void PopUpCard::quit(){
    this->close();
}
