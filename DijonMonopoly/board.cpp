#include "board.h"

Board::Board()
{
    this->dices.push_back(0);
    this->dices.push_back(0);
    this->playerIndex = 0;

    this->createBoard();
}

void Board::createBoard() {
    this->cases.push_back(new class CornerCase(1057, 777, 0, typeCornerCase::Depart));
    this->cases.push_back(new class Estate(964, 777, 1, "Rue Alix de Vergy", colorEstate::Brown, 60, {2,10,30,90,160,250}, "../../../../CardEstate/vergy.png"));
    this->cases.push_back(new class DrawCard(898,777,2,typeDrawCard::ComCard));
    this->cases.push_back(new class Estate(832, 777 , 3, "Place des Savoirs", colorEstate::Brown, 60,{4,20,60,180,320,450},"../../../../CardEstate/savoirs.png"));
    this->cases.push_back(new class Taxe(766, 777, 4, "Impôt sur le revenu", 200));
    this->cases.push_back(new class Gare(700, 777, 5, "Arrêt Grésille", 200));
    this->cases.push_back(new class Estate(634,777, 6, "Rue Dubois", colorEstate::LightBlue, 100,{6,30,90,270,400,550}, "../../../../CardEstate/dubois.png"));
    this->cases.push_back(new class DrawCard(568,777,7,typeDrawCard::ChanceCard));
    this->cases.push_back(new class Estate(502, 777, 8, "Rue des Marmuzots", colorEstate::LightBlue, 100, {6,30,90,270,400,550},"../../../../CardEstate/marmuzots.png"));
    this->cases.push_back(new class Estate(436, 777, 9, "Rue Vannerie", colorEstate::LightBlue, 120, {8,40,100,300,450,600},"../../../../CardEstate/vannerie.png"));
    this->cases.push_back(new class CornerCase(343, 777, 10, typeCornerCase::Prison));
    this->cases.push_back(new class Estate(343, 684,11, "Rue Sully", colorEstate::Purple, 140,{10,50,150,450,625,750}, "../../../../CardEstate/sully.png") );
    this->cases.push_back(new class Company(343,618,12,"EDF",150));
    this->cases.push_back(new class Estate(343,552,13,"Boulevard Gabriel", colorEstate::Purple, 140,{10,50,150,450,625,750},"../../../../CardEstate/gabriel.png") );
    this->cases.push_back(new class Estate(343,486,14,"Rue d'Auxonne", colorEstate::Purple, 160,{12,60,180,500,700,900}, "../../../../CardEstate/auxonne.png") );
    this->cases.push_back(new class Gare(343,420,15,"Arrêt Monge",200) );
    this->cases.push_back(new class Estate(343,354,16,"Rue Berbisey", colorEstate::Orange, 180,{14,70,200,550,750,950} ,"../../../../CardEstate/berbisey.png") );
    this->cases.push_back(new class Estate(343,288,17,"Rue Charrue",colorEstate::Orange, 180, {14,70,200,550,750,950} ,"../../../../CardEstate/charrue.png") );
    this->cases.push_back(new class DrawCard(343,222,18,typeDrawCard::ComCard) );
    this->cases.push_back(new class Estate(343,156,19,"Place Emile Zola", colorEstate::Orange, 200, {16,80,220,600,800,1000},"../../../../CardEstate/zola.png") );
    this->cases.push_back(new class CornerCase(343,63,20,typeCornerCase::Parc) );
    this->cases.push_back(new class Estate(436,63,21, "Rue Claude Cazotte", colorEstate::Red,220,{18,90,250,700,875,1050} ,"../../../../CardEstate/cazotte.png") );
    this->cases.push_back(new class DrawCard(502,63,22,typeDrawCard::ChanceCard) );
    this->cases.push_back(new class Estate(568,63,23,"Rue Danton", colorEstate::Red, 220,{18,90,250,700,875,1050}, "../../../../CardEstate/danton.png") );
    this->cases.push_back(new class Estate(634,63,24,"Rue de Tivoli",colorEstate::Red, 240, {18,90,250,700,875,1050}, "../../../../CardEstate/tivoli.png") );
    this->cases.push_back(new class Gare(700,63,25,"Arrêt République",200) );
    this->cases.push_back(new class Estate(766,63,26,"Boulevard Thiers",colorEstate::Yellow, 260, {22,110,330,800,975,1150}, "../../../../CardEstate/thiers.png") );
    this->cases.push_back(new class Estate(832,63,27,"Boulevard Carnot", colorEstate::Yellow, 260,{22,110,330,800,975,1150}, "../../../../CardEstate/carnot.png") );
    this->cases.push_back(new class Company(898,63,28,"SUEZ",150) );
    this->cases.push_back(new class Estate(964,63,29,"Place du 30 Octobre", colorEstate::Yellow,280,{24,120,360,830,1025,1200}, "../../../../CardEstate/octobre.png") );
    this->cases.push_back(new class CornerCase(1057,63,30,typeCornerCase::Police) );
    this->cases.push_back(new class Estate(1057,156,31,"Rue de la préfecture", colorEstate::Green, 300,{26,130,390,900,1100,1275}, "../../../../CardEstate/prefecture.png") );
    this->cases.push_back(new class Estate(1057,222,32,"Rue des Godrans",colorEstate::Green, 300,{26,130,390,900,1100,1275}, "../../../../CardEstate/godrans.png") );
    this->cases.push_back(new class DrawCard(1057,288,33,typeDrawCard::ComCard) );
    this->cases.push_back(new class Estate(1057,354,34,"Avenue Victor Hugo",colorEstate::Green,320,{28,150,450,1000,1200,1400}, "../../../../CardEstate/hugo.png") );
    this->cases.push_back(new class Gare(1057,420,35,"Arrêt Darcy",200) );
    this->cases.push_back(new class DrawCard(1057,486,36,typeDrawCard::ChanceCard) );
    this->cases.push_back(new class Estate(1057,552,37,"Boulevard de la Trémouille",colorEstate::DarkBlue, 350,{35,175,500,1100,1300,1500}, "../../../../CardEstate/tremouille.png") );
    this->cases.push_back(new class Taxe(1057,618,38,"Galerie de La Fayette",100) );
    this->cases.push_back(new class Estate(1057,684,39, "Rue de la liberté",colorEstate::DarkBlue, 400,{50,200,600,1400,1700,2000} ,"../../../../CardEstate/liberte.png") );
}

double Board::getPlayerIndex() const {
    return this->playerIndex;
}

bool Board::isADouble() const {
    return this->dices[0] == this->dices[1];
}

int Board::getSumDice(void) const {
    return this->dices.at(0) + this->dices.at(1);
}

int Board::getDice1() {
    return this->dices[0];
}

int Board::getDice2() {
    return this->dices[1];
}

Player* Board::getCurrentPlayer() {
    return this->players[this->playerIndex];
}

Case* Board::getCaseOfCurrentPlayer() {
    return this->cases[this->getCurrentPlayer()->getLocalisation()];
}

std::vector<Player*> Board::getPlayers() const {
    return this->players;
}

Case* Board::getCaseAt(int index) {
    if (index >= 0 && index < (int)this->cases.size()) {
        return this->cases.at(index);
    }
    return nullptr;
}

void Board::setPlayers(std::vector<Player *> p) {
    this->players = p;
}

void Board::addPlayer(Player *p) {
    this->players.push_back(p);
}

void Board::throwDice() {
    Dice d = Dice();
    this->dices[0] = d.throwDice();
    this->dices[1] = d.throwDice();
    std::cout << this->getCurrentPlayer()->getName() << " makes " << this->dices[0] << " and " << this->dices[1] <<std::endl;
}

void Board::nextPlayer() {
    if (!this->isADouble()) {
        this->playerIndex += 1;
        if (this->playerIndex - this->players.size() >= 0 ) {
            this->playerIndex = 0;
        }
        std::cout << "Change player, now it's " << this->getCurrentPlayer()->getName() << std::endl;
    }
}

void Board::currentPlayerBuyCurrentEstate() {
    class Estate* e = static_cast<class Estate*>(this->getCaseOfCurrentPlayer());
    if (e->getPrice() <= this->getCurrentPlayer()->getMoney()) {
        // Player can buy estate
        e->setOwner(this->getCurrentPlayer());
        this->getCurrentPlayer()->looseMoney(e->getPrice());
        this->getCurrentPlayer()->addProperties(e);
        std::cout << this->getCurrentPlayer()->getName() << " buys the estate : " << e->getName() << std::endl;
    }
    delete e;
}

void Board::gameTurn(MainWindow* w) {
    if (this->getCurrentPlayer()->getIsInJail()) {
        // manage when the player is in jail
    } else {
        this->throwDice();
        // calculate if player pass through the depart case
        if (this->getCurrentPlayer()->getLocalisation() + this->getSumDice() > 40) {
            this->getCurrentPlayer()->earnMoney(200);
        }
        this->getCurrentPlayer()->advanceTo(this->getSumDice());

        // check on which case the player go
        switch (this->getCaseOfCurrentPlayer()->getTypeCase()) {
        case typeOfCase::Company : {
            class Company* c = static_cast<class Company*>(this->getCaseOfCurrentPlayer());
            std::cout << "The player " << this->getCurrentPlayer()->getName() << " is on a company case : " << c->getName() << std::endl;
            this->onCompanyCase(c,w);
            break;
        }
        case typeOfCase::CornerCase : {
            class CornerCase* c = static_cast<class CornerCase*>(this->getCaseOfCurrentPlayer());
            std::cout << "The player " << this->getCurrentPlayer()->getName() << " is on a Corner case : " << c->getName() << ", " << c->getType() << std::endl;
            this->onCornerCase(c,w);
            break;
        }
        case typeOfCase::Draw : {
            class DrawCard* d = static_cast<class DrawCard*>(this->getCaseOfCurrentPlayer());
            std::cout << "The player " << this->getCurrentPlayer()->getName() << " is on a Draw case : " << d->getTypeCase() << std::endl;
            this->onDrawCase(d,w);
            break;
        }
        case typeOfCase::Estate : {
            class Estate* e = static_cast<class Estate*>(this->getCaseOfCurrentPlayer());
            std::cout << "The player " << this->getCurrentPlayer()->getName() << " is on a Estate case : " << e->getName() << std::endl;
            this->onEstateCase(e,w);
            break;
        }
        case typeOfCase::Gare : {
            class Gare* g = static_cast<class Gare*>(this->getCaseOfCurrentPlayer());
            std::cout << "The player " << this->getCurrentPlayer()->getName() << " is on a company case : " << g->getName() << std::endl;
            this->onGareCase(g,w);
            break;
        }
        case typeOfCase::Taxe : {
            class Taxe* t = static_cast<class Taxe*>(this->getCaseOfCurrentPlayer());
            std::cout << "The player " << this->getCurrentPlayer()->getName() << " is on a company case : " << t->getName() << std::endl;
            this->onTaxeCase(t,w);
            break;
        }
        }
    }
    this->refreshViewDelegate(w);
}

void Board::onEstateCase(class Estate* e, MainWindow* w) {
    if (e->getOwner() == nullptr) {
        // estate hasn't got a owner. Pop a buying pop-up
        this->popUpBuyEstate(w,e);
    } else {
        if (this->getCurrentPlayer() == e->getOwner()) {
            // the player and the owner is the same
            // check if the player has got all estate with same color.
        } else {
            // the current player needs to pay the owner
            std::cout << this->getCurrentPlayer()->getName() << " is on the estate of " << e->getOwner()->getName() << std::endl;
            e->payRent(this->getCurrentPlayer());
            this->popUpPayRent(w,e,this->getCurrentPlayer());
        }
    }
}

void Board::onGareCase(class Gare *g, MainWindow* w) {
    if (g->getOwner() == nullptr) {
        // gare hasn't got a owner. Pop a buying pop-up
    } else {
        if (this->getCurrentPlayer() == g->getOwner()) {
            // the player and the owner is the same
        } else {
            // the current player needs to pay the owner
            g->payRent(this->getCurrentPlayer());
        }
    }
}

void Board::onCornerCase(class CornerCase *c, MainWindow* w) {
    // make the right action related by the corner case
    //c->actionRelated(this->getCurrentPlayer());
}

void Board::onTaxeCase(class Taxe *t, MainWindow* w) {
    this->getCurrentPlayer()->looseMoney(t->getPrice());
}

void Board::onCompanyCase(class Company *c, MainWindow* w) {
    if (c->getOwner() == nullptr) {
        // Company hasn't got a owner. Pop a buying pop-up.
    } else {
        if (this->getCurrentPlayer() != c->getOwner()) {
            // the player and the owner isn't the same
            c->payRent(this->getCurrentPlayer());
        }
    }
}

void Board::onDrawCase(class DrawCard *d, MainWindow* w) {
    // drawing a card
}

