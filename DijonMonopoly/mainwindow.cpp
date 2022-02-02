#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    this->setWindowTitle("Dij'Monop");
    this->setGeometry(0,0,1400,840);
    this->setFixedSize(this->size());
    this->initComponents();
    this->initLayout();
    this->initSlots();
    this->board = new Board();
    this->t = std::time(0);
}

MainWindow::~MainWindow()
{
    delete(this->scene);
    delete(this->view);
}

void MainWindow::startMainWindow() {
    this->initPlayer();
}

void MainWindow::initComponents() {
    this->scene = new QGraphicsScene();
    this->view = new QGraphicsView(this->scene);
    this->scene->setBackgroundBrush(QBrush(Qt::gray, Qt::SolidPattern));
    QPen blackPen(Qt::black);
    QBrush greenBrush(QColor(210,230,210));
    this->physicPlateau = this->scene->addRect(0,0,834,834, blackPen,greenBrush);
    this->physicPlateau->setPos(283,3);
    this->physicPlateau->setFlag(QGraphicsItem::ItemIsSelectable, true);
    QGraphicsTextItem* monopolyText = new QGraphicsTextItem("DIJ' MONOP");
    monopolyText->setScale(8);
    monopolyText->setPos(410,575);
    monopolyText->setRotation(-45);
    this->scene->addItem(monopolyText);

    // Throw dice button
    this->throwDiceBtn = this->scene->addPixmap(QPixmap("../../../../Autres/dice.png"));
    this->throwDiceBtn->setScale(0.3);
    this->throwDiceBtn->setFlag(QGraphicsItem::ItemIsSelectable, true);
    // text which indicates score dice
    this->scoreDice = this->scene->addText("");
    this->scoreDice->setDefaultTextColor(QColor(Qt::black));
    // pixmap which give detail on a case
    this->cardInfo = new QGraphicsPixmapItem();
    this->scene->addItem(this->cardInfo);
    this->cardInfo->setPos(618,222);
    // text which give detail on a case
    this->cardInfoOwner = new QGraphicsTextItem("");
    this->scene->addItem(this->cardInfoOwner);
}

void MainWindow::initLayout() {
    this->setCentralWidget(this->view);
    this->initCases();

    this->throwDiceBtn->setPos(700-(this->throwDiceBtn->boundingRect().size().rwidth()*0.3/2),610);
    this->scoreDice->setPos(700-(this->scoreDice->boundingRect().size().rwidth()/2), 580);
    this->cardInfoOwner->setPos(700-(this->cardInfoOwner->boundingRect().size().rwidth()/2),200);
}

void MainWindow::initSlots() {
    QWidget::connect(this->scene, SIGNAL(selectionChanged()),this, SLOT(whichCaseIsSelected()));
}


void MainWindow::initCases() {
    this->cases.push_back(this->scene->addPixmap(QPixmap("../Cases/depart.png")));
    this->cases[0]->setPos(997,717);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/vergy.png")));
    this->cases[1]->setPos(931,717);
    this->cases[1]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/gouv.png")));
    this->cases[2]->setPos(865,717);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/savoirs.png")));
    this->cases[3]->setPos(799,717);
    this->cases[3]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/impot.png")));
    this->cases[4]->setPos(733,717);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/arret1.png")));
    this->cases[5]->setPos(667,717);
    this->cases[5]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/dubois.png")));
    this->cases[6]->setPos(601,717);
    this->cases[6]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/chance.png")));
    this->cases[7]->setPos(535,717);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/marmuzots.png")));
    this->cases[8]->setPos(469,717);
    this->cases[8]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/vannerie.png")));
    this->cases[9]->setPos(403,717);
    this->cases[9]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/prison.png")));
    this->cases[10]->setPos(283,717);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/sully.png")));
    this->cases[11]->setPos(403,651);
    this->cases[11]->setRotation(90);
    this->cases[11]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/edf.png")));
    this->cases[12]->setPos(403,585);
    this->cases[12]->setRotation(90);
    this->cases[12]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/gabriel.png")));
    this->cases[13]->setPos(403,519);
    this->cases[13]->setRotation(90);
    this->cases[13]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/auxonne.png")));
    this->cases[14]->setPos(403,453);
    this->cases[14]->setRotation(90);
    this->cases[14]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/arret2.png")));
    this->cases[15]->setPos(403,387);
    this->cases[15]->setRotation(90);
    this->cases[15]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/berbisey.png")));
    this->cases[16]->setPos(403,321);
    this->cases[16]->setRotation(90);
    this->cases[16]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/charrue.png")));
    this->cases[17]->setPos(403,255);
    this->cases[17]->setRotation(90);
    this->cases[17]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/gouv.png")));
    this->cases[18]->setPos(403,189);
    this->cases[18]->setRotation(90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/zola.png")));
    this->cases[19]->setPos(403,123);
    this->cases[19]->setRotation(90);
    this->cases[19]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/parc.png")));
    this->cases[20]->setPos(283,3);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/cazotte.png")));
    this->cases[21]->setPos(469,123);
    this->cases[21]->setRotation(180);
    this->cases[21]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/chance.png")));
    this->cases[22]->setPos(535,123);
    this->cases[22]->setRotation(180);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/danton.png")));
    this->cases[23]->setPos(601,123);
    this->cases[23]->setRotation(180);
    this->cases[23]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/tivoli.png")));
    this->cases[24]->setPos(667,123);
    this->cases[24]->setRotation(180);
    this->cases[24]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/arret3.png")));
    this->cases[25]->setPos(733,123);
    this->cases[25]->setRotation(180);
    this->cases[25]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/thiers.png")));
    this->cases[26]->setPos(799,123);
    this->cases[26]->setRotation(180);
    this->cases[26]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/carnot.png")));
    this->cases[27]->setPos(865,123);
    this->cases[27]->setRotation(180);
    this->cases[27]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/suez.png")));
    this->cases[28]->setPos(931,123);
    this->cases[28]->setRotation(180);
    this->cases[28]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/octobre.png")));
    this->cases[29]->setPos(997,123);
    this->cases[29]->setRotation(180);
    this->cases[29]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/prison2.png")));
    this->cases[30]->setPos(997,3);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/prefecture.png")));
    this->cases[31]->setPos(997,189);
    this->cases[31]->setRotation(-90);
    this->cases[31]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/godrans.png")));
    this->cases[32]->setPos(997,255);
    this->cases[32]->setRotation(-90);
    this->cases[32]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/gouv.png")));
    this->cases[33]->setPos(997,321);
    this->cases[33]->setRotation(-90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/hugo.png")));
    this->cases[34]->setPos(997,387);
    this->cases[34]->setRotation(-90);
    this->cases[34]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/arret4.png")));
    this->cases[35]->setPos(997,453);
    this->cases[35]->setRotation(-90);
    this->cases[35]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/chance.png")));
    this->cases[36]->setPos(997,519);
    this->cases[36]->setRotation(-90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/tremouille.png")));
    this->cases[37]->setPos(997,585);
    this->cases[37]->setRotation(-90);
    this->cases[37]->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/lafayette.png")));
    this->cases[38]->setPos(997,651);
    this->cases[38]->setRotation(-90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/liberte.png")));
    this->cases[39]->setPos(997,717);
    this->cases[39]->setRotation(-90);
    this->cases[39]->setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void MainWindow::initPlayer() {
    // make the pop up at the begining
    this->popPlayer = new PopUpAddPlayer(this);
    this->popPlayer->show();
}

void MainWindow::initPlayerUI(std::vector<std::string> names) {
    // Create all the ui for the player
    for (int i=0; i< (int) names.size() ; i++) {
        QGraphicsTextItem* text = new QGraphicsTextItem( QString::fromStdString( names[i] ));
        QGraphicsTextItem* money = new QGraphicsTextItem( "2000 M" );
        QGraphicsTextItem* nb = new QGraphicsTextItem( "Nombre Propriété : 0" );
        QGraphicsTextItem* p = new QGraphicsTextItem( "'Libéré de prison' : 0" );
        QGraphicsRectItem* player = this->scene->addRect(0,0,30,30, QPen(Qt::red), QBrush(Qt::red));
        this->board->addPlayer(new Player(names[i], "chien",2000));
        this->physicalPlayers.push_back(player);
        this->playersNames.push_back(text);
        this->playersMoney.push_back(money);
        this->playersNbProp.push_back(nb);
        this->playersPrisonCard.push_back(p);
        this->scene->addItem(text);
        this->scene->addItem(money);
        this->scene->addItem(nb);
        this->scene->addItem(p);
    }
    this->physicalPlayers[0]->setPos(1022,742);
    this->playersNames[0]->setPos(20,20);
    this->playersMoney[0]->setPos(20,40);
    this->playersNbProp[0]->setPos(20,60);
    this->playersPrisonCard[0]->setPos(20,80);
    this->physicalPlayers[1]->setPos(1022,782);
    this->playersNames[1]->setPos(20,740);
    this->playersMoney[1]->setPos(20,760);
    this->playersNbProp[1]->setPos(20,780);
    this->playersPrisonCard[1]->setPos(20,800);
    this->physicalPlayers[2]->setPos(1062,742);
    this->playersNames[2]->setPos(1137,20);
    this->playersMoney[2]->setPos(1137,40);
    this->playersNbProp[2]->setPos(1137,60);
    this->playersPrisonCard[2]->setPos(1137,80);
    this->physicalPlayers[3]->setPos(1062,782);
    this->playersNames[3]->setPos(1137,740);
    this->playersMoney[3]->setPos(1137,760);
    this->playersNbProp[3]->setPos(1137,780);
    this->playersPrisonCard[3]->setPos(1137,800);
    this->playersRectUI.push_back(this->scene->addRect(10,10,263,100, QPen(Qt::black)));
    this->playersRectUI.push_back(this->scene->addRect(10,730,263,100, QPen(Qt::black)));
    this->playersRectUI.push_back(this->scene->addRect(1127,10,263,100, QPen(Qt::black)));
    this->playersRectUI.push_back(this->scene->addRect(1127,730,263,100, QPen(Qt::black)));
}

void MainWindow::gameTurn() {
    std::cout << std::endl <<"-------------------- Next Turn --------------------" << std::endl;
    this->board->gameTurn(this);
}

void MainWindow::whichCaseIsSelected() {
    // Check which case is selected
    this->scoreDice->setPos(700-(this->scoreDice->boundingRect().size().rwidth()/2), 580);
    if (this->scene->selectedItems().size() > 0) {
        this->cardInfoOwner->setPlainText("");
        if (this->scene->selectedItems().at(0) == this->throwDiceBtn && std::time(0) - this->t > 1) { // avoid boucing
            this->board->nextPlayer();
            this->t = std::time(0);
            this->gameTurn();
            this->cardInfo->setPixmap(QPixmap(""));
        } else if (this->scene->selectedItems().at(0) == this->physicPlateau){
            this->cardInfo->setPixmap(QPixmap(""));
        }else if (this->scene->selectedItems().at(0) == this->cases.at(1)) {
            this->setCardInfo(1);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(3)) {
            this->setCardInfo(3);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(5)) {
            this->setCardInfo(5);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(6)) {
            this->setCardInfo(6);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(8)) {
            this->setCardInfo(8);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(9)) {
            this->setCardInfo(9);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(11)) {
            this->setCardInfo(11);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(12)) {
            this->setCardInfo(12);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(13)) {
            this->setCardInfo(13);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(14)) {
            this->setCardInfo(14);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(15)) {
            this->setCardInfo(15);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(16)) {
            this->setCardInfo(16);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(17)) {
            this->setCardInfo(17);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(19)) {
            this->setCardInfo(19);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(21)) {
            this->setCardInfo(21);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(23)) {
            this->setCardInfo(23);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(24)) {
            this->setCardInfo(24);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(25)) {
            this->setCardInfo(25);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(26)) {
            this->setCardInfo(26);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(27)) {
            this->setCardInfo(27);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(28)) {
            this->setCardInfo(28);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(29)) {
            this->setCardInfo(29);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(31)) {
            this->setCardInfo(31);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(32)) {
            this->setCardInfo(32);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(34)) {
            this->setCardInfo(34);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(35)) {
            this->setCardInfo(35);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(37)) {
            this->setCardInfo(37);
        }else if (this->scene->selectedItems().at(0) == this->cases.at(39)) {
            this->setCardInfo(39);
        }
    }
    this->scene->clearSelection();
}

void MainWindow::setCardInfo(int num) {
    // What display when click on a case
    if (this->board->getCaseAt(num)->getOwner() != nullptr ) {
        this->cardInfoOwner->setPlainText(QString::fromStdString("Cette carte appartient à "+this->board->getCaseAt(num)->getOwner()->getName()));
        this->cardInfoOwner->setPos(700-(this->cardInfoOwner->boundingRect().size().rwidth()/2),200);
    }
    this->cardInfo->setPixmap(QPixmap(QString::fromStdString(this->board->getCaseAt(num)->getPath())));
}

void MainWindow::refreshView() {
    std::cout << " 'refresh view' " << std::endl;
    this->refreshDice();
    this->refreshPlayerPhysical();
    this->refreshPlayerUI();
}

void MainWindow::refreshDice() {
    std::string s =this->board->getCurrentPlayer()->getName() + " a fait " + std::to_string(this->board->getDice1()) + " et " + std::to_string(this->board->getDice2()) ;
    this->scoreDice->setPlainText( QString::fromStdString(s) );
    this->scoreDice->setPos(700-(this->scoreDice->boundingRect().size().rwidth()/2), 580);
}

void MainWindow::refreshPlayerPhysical() {
    // Move players
    this->physicalPlayers.at(this->board->getPlayerIndex())->setPos(this->board->getCaseOfCurrentPlayer()->getCoordCenter());
    std::cout << this->board->getPlayerIndex() << " change his position " << this->board->getCaseOfCurrentPlayer()->getCoordCenter().x() << " " << this->board->getCaseOfCurrentPlayer()->getCoordCenter().y() << std::endl;
}

void MainWindow::refreshPlayerUI(void) {
    // Refresh money, owned estate ..
    for (int i=0; i<(int)this->board->getPlayers().size();i++) {
        this->playersMoney[i]->setPlainText(QString::fromStdString(std::to_string(this->board->getPlayers().at(i)->getMoney())+" M"));
        this->playersNbProp[i]->setPlainText(QString::fromStdString("Nombre Propriété : " + std::to_string(this->board->getPlayers().at(i)->getProperties().size())));
        this->playersPrisonCard[i]->setPlainText(QString::fromStdString("'Libéré de prison : "+ std::to_string(this->board->getPlayers().at(i)->getFreeJailCard())));
    }

    // Refresh which is the current player ( draw green rectangle on it)
    for (int i=0; i<(int)this->playersRectUI.size(); i++) {
        this->playersRectUI[i]->setPen(QPen(Qt::black));
    }
   this->playersRectUI[this->board->getPlayerIndex()]->setPen(QPen(Qt::green));

}

//void MainWindow::popUpBuyEstate(class Estate* e) {
void MainWindow::popUpBuyEstate(Case *e) {
    this->popBuyEstate = new PopUpBuyEstate(this,e,this->board->getCurrentPlayer());
    this->popBuyEstate->show();
}

void MainWindow::receiveBuyEstate(bool answer) {
    if (answer)
        this->board->currentPlayerBuyCurrentEstate();
    this->refreshPlayerUI();
}

void MainWindow::popUpPayRent(Case *e, class Player* buyer, int sumDice) {
    this->popBuyRent = new PopUpPayRent(e,buyer, sumDice);
    this->popBuyRent->show();
}

// -------------------------------------------------------------------------------------------------------------
// BOARD METHODS DEFINITION

void Board::refreshViewDelegate(MainWindow *w) {
    w->refreshView();
}

//void Board::popUpBuyEstate(MainWindow *w, class Estate* e) {
void Board::popUpBuy(MainWindow *w, Case *e) {
    w->popUpBuyEstate(e);
}

void Board::popUpPayRent(MainWindow *w, Case *e, class Player* buyer, int sumDice) {
    w->popUpPayRent(e,buyer);
}
