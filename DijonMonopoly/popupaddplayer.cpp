#include "popupaddplayer.h"

PopUpAddPlayer::PopUpAddPlayer(QWidget *parent): QMainWindow(parent)
{
    this->parent = parent;
    this->setWindowTitle("Ajouter le nom des joueurs");
    this->setGeometry(650,300,400,200);
    this->setFixedSize(this->size());
    this->initComponent();
    this->initLayout();
    this->initSlots();
}

void PopUpAddPlayer::initComponent() {
    this->centre = new QWidget();
    this->p1 = new QLabel("Joueur 1");
    this->player1 = new QLineEdit();
    this->p2 = new QLabel("Joueur 2");
    this->player2 = new QLineEdit();
    this->p3 = new QLabel("Joueur 3");
    this->player3 = new QLineEdit();
    this->p4 = new QLabel("Joueur 4");
    this->player4 = new QLineEdit();
    this->piece1 = new QLabel("Pièce 1");
    this->piece2 = new QLabel("Pièce 2");
    this->piece3 = new QLabel("Pièce 3");
    this->piece4 = new QLabel("Pièce 4");
    this->liste_deroulante1 = new QComboBox(this);
    this->liste_deroulante1->addItem("Rouge");
    this->liste_deroulante1->addItem("Bleu");
    this->liste_deroulante1->addItem("Vert");
    this->liste_deroulante1->addItem("Magenta");
    this->liste_deroulante1->addItem("Jaune");
    this->liste_deroulante1->addItem("Noir");
    this->liste_deroulante1->addItem("Gris");
    this->liste_deroulante1->addItem("Cyan");
    this->liste_deroulante2 = new QComboBox(this);
    this->liste_deroulante2->addItem("Rouge");
    this->liste_deroulante2->addItem("Bleu");
    this->liste_deroulante2->addItem("Vert");
    this->liste_deroulante2->addItem("Magenta");
    this->liste_deroulante2->addItem("Jaune");
    this->liste_deroulante2->addItem("Noir");
    this->liste_deroulante2->addItem("Gris");
    this->liste_deroulante2->addItem("Cyan");
    this->liste_deroulante3 = new QComboBox(this);
    this->liste_deroulante3->addItem("Rouge");
    this->liste_deroulante3->addItem("Bleu");
    this->liste_deroulante3->addItem("Vert");
    this->liste_deroulante3->addItem("Magenta");
    this->liste_deroulante3->addItem("Jaune");
    this->liste_deroulante3->addItem("Noir");
    this->liste_deroulante3->addItem("Gris");
    this->liste_deroulante3->addItem("Cyan");
    this->liste_deroulante4 = new QComboBox(this);
    this->liste_deroulante4->addItem("Rouge");
    this->liste_deroulante4->addItem("Bleu");
    this->liste_deroulante4->addItem("Vert");
    this->liste_deroulante4->addItem("Magenta");
    this->liste_deroulante4->addItem("Jaune");
    this->liste_deroulante4->addItem("Noir");
    this->liste_deroulante4->addItem("Gris");
    this->liste_deroulante4->addItem("Cyan");
    this->button = new QPushButton("Nouvelle partie");
}

void PopUpAddPlayer::initLayout() {
    this->setCentralWidget(this->centre);
    //this->formLayout = new QFormLayout();
    this->gridLayout = new QGridLayout();
    this->centre->setLayout(this->gridLayout);
    this->gridLayout->addWidget(this->p1, 0 ,0);
    this->gridLayout->addWidget(this->player1, 0 ,1);
    this->gridLayout->addWidget(this->p2, 1 ,0);
    this->gridLayout->addWidget(this->player2, 1 ,1);
    this->gridLayout->addWidget(this->p3, 2 ,0);
    this->gridLayout->addWidget(this->player3, 2 ,1);
    this->gridLayout->addWidget(this->p4, 3 ,0);
    this->gridLayout->addWidget(this->player4, 3 ,1);
    this->gridLayout->addWidget(this->piece1, 0, 2);
    this->gridLayout->addWidget(this->piece2, 1, 2);
    this->gridLayout->addWidget(this->piece3, 2, 2);
    this->gridLayout->addWidget(this->piece4, 3, 2);
    this->gridLayout->addWidget(this->liste_deroulante1, 0, 3);
    this->gridLayout->addWidget(this->liste_deroulante2, 1, 3);
    this->gridLayout->addWidget(this->liste_deroulante3, 2, 3);
    this->gridLayout->addWidget(this->liste_deroulante4, 3, 3);
    this->gridLayout->addWidget(this->button, 4,3);
}

void PopUpAddPlayer::initSlots() {
    QWidget::connect(this->button, SIGNAL(clicked()), this, SLOT(preparePlayer()));
    QWidget::connect(this, SIGNAL(newPlayerSignal(std::vector<std::string>, std::vector<std::string>)), this->parent, SLOT(initPlayerUI(std::vector<std::string>, std::vector<std::string>)));
}

void PopUpAddPlayer::preparePlayer() {
    std::vector<std::string> names = std::vector<std::string>();
    std::vector<std::string> color = std::vector<std::string>();
    names.push_back(this->player1->text().toStdString());
    names.push_back(this->player2->text().toStdString());
    names.push_back(this->player3->text().toStdString());
    names.push_back(this->player4->text().toStdString());
    color.push_back(this->liste_deroulante1->currentText().toStdString());
    color.push_back(this->liste_deroulante2->currentText().toStdString());
    color.push_back(this->liste_deroulante3->currentText().toStdString());
    color.push_back(this->liste_deroulante4->currentText().toStdString());
    std::cout << color.size() << std::endl;
    emit newPlayerSignal(names, color);
    this->close();
}

