#include "popupbuygare.h"

PopUpBuyGare::PopUpBuyGare(QWidget *parent, class Gare* g, Player* p) :QMainWindow(parent)
{
    this->parent = parent;
    this->gare = g;
    this->p = p;
    this->initComponent();
    this->initLayout();
    this->initSlot();
}

void PopUpBuyGare::initComponent() {
    this->centre = new QWidget();
    this->yesButton = new QPushButton("Oui");
    this->noButton = new QPushButton("Non");
    this->label = new QLabel(QString::fromStdString(this->p->getName()+" voulez-vous acheter "+this->gare->getName()+" pour "+std::to_string((int)this->estate->getPrice())+"M ?"));
}

void PopUpBuyGare::initLayout() {
    this->setCentralWidget(this->centre);
    this->vbox = new QVBoxLayout();
    this->hbox = new QHBoxLayout();
    this->centre->setLayout(this->vbox);
    this->vbox->addWidget(this->label);
    this->vbox->addLayout(this->hbox);
    this->hbox->addWidget(this->yesButton);
    this->hbox->addWidget(this->noButton);
}

void PopUpBuyGare::initSlot() {
    QWidget::connect(this->yesButton, SIGNAL(clicked()), this, SLOT(trueReturn()));
    QWidget::connect(this->noButton, SIGNAL(clicked()), this, SLOT(falseReturn()));
    QWidget::connect(this, SIGNAL(answerBuyGare(bool)), this->parent, SLOT(receiveBuyEstate(bool)));
}

void PopUpBuyGare::falseReturn() {
    emit answerBuyGare(false);
    this->close();
}

void PopUpBuyGare::trueReturn() {
    emit answerBuyGare(true);
    this->close();
}

