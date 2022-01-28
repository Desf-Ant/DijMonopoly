#include "popupaddplayer.h"

PopUpAddPlayer::PopUpAddPlayer(QWidget *parent): QMainWindow(parent)
{
    this->parent = parent;
    this->setWindowTitle("Ajouter le nom des joueurs");
    this->setGeometry(650,300,300,200);
    this->setFixedSize(this->size());
    this->initComponent();
    this->initLayout();
    this->initSlots();
}

void PopUpAddPlayer::initComponent() {
    this->centre = new QWidget();
    this->player1 = new QLineEdit();
    this->player2 = new QLineEdit();
    this->player3 = new QLineEdit();
    this->player4 = new QLineEdit();
    this->button = new QPushButton("Créer une nouvelle partie");
}

void PopUpAddPlayer::initLayout() {
    this->setCentralWidget(this->centre);
    this->formLayout = new QFormLayout();
    this->centre->setLayout(this->formLayout);
    this->formLayout->addRow("Joueur 1", this->player1);
    this->formLayout->addRow("Joueur 2", this->player2);
    this->formLayout->addRow("Joueur 3", this->player3);
    this->formLayout->addRow("Joueur 4", this->player4);
    this->formLayout->addWidget(this->button);
}

void PopUpAddPlayer::initSlots() {
    QWidget::connect(this->button, SIGNAL(clicked()), this, SLOT(preparePlayer()));
    QWidget::connect(this, SIGNAL(newPlayerSignal(std::vector<std::string>)), this->parent, SLOT(initPlayerUI(std::vector<std::string>)));
}

void PopUpAddPlayer::preparePlayer() {
    std::vector<std::string> names = std::vector<std::string>();
    names.push_back(this->player1->text().toStdString());
    names.push_back(this->player2->text().toStdString());
    names.push_back(this->player3->text().toStdString());
    names.push_back(this->player4->text().toStdString());
    emit newPlayerSignal(names);
    this->close();
}
