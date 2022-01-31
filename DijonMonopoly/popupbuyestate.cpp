#include "popupbuyestate.h"

//PopUpBuyEstate::PopUpBuyEstate(QWidget *parent, class Estate* e, Player* p) :QMainWindow(parent)
PopUpBuyEstate::PopUpBuyEstate(QWidget *parent, Case* e, Player* p) :QMainWindow(parent)
{
    this->parent = parent;
    this->estate = e;
    this->p = p;
    this->pathImage = e->getPath();
    this->initComponent();
    this->initLayout();
    this->initSlot();
}

void PopUpBuyEstate::initComponent() {
    this->centre = new QWidget();
    this->yesButton = new QPushButton("Oui");
    this->noButton = new QPushButton("Non");
    this->label = new QLabel(QString::fromStdString(this->p->getName()+" voulez-vous acheter "+this->estate->getName()+" pour "+std::to_string((int)this->estate->getPrice())+"M ?"));
    this->labelCard = new QLabel();
    this->labelCard->setPixmap(QPixmap(QString::fromStdString(this->pathImage)));
}

void PopUpBuyEstate::initLayout() {
    this->setCentralWidget(this->centre);
    this->vbox = new QVBoxLayout();
    this->hbox = new QHBoxLayout();
    this->centre->setLayout(this->vbox);
    this->vbox->addWidget(this->label);
    this->vbox->addWidget(this->labelCard);
    this->labelCard->setAlignment(Qt::AlignCenter);
    this->vbox->addLayout(this->hbox);
    this->hbox->addWidget(this->yesButton);
    this->hbox->addWidget(this->noButton);
}

void PopUpBuyEstate::initSlot() {
    QWidget::connect(this->yesButton, SIGNAL(clicked()), this, SLOT(trueReturn()));
    QWidget::connect(this->noButton, SIGNAL(clicked()), this, SLOT(falseReturn()));
    QWidget::connect(this, SIGNAL(answerBuyEstate(bool)), this->parent, SLOT(receiveBuyEstate(bool)));
}

void PopUpBuyEstate::falseReturn() {
    emit answerBuyEstate(false);
    this->close();
}

void PopUpBuyEstate::trueReturn() {
    emit answerBuyEstate(true);
    this->close();
}
