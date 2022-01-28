#include "board.h"

Board::Board()
{
    this->dices[0] = 0;
    this->dices[1] = 0;
    this->playerIndex = 0;

    this->createBoard();
}

Board::Board(void (*refreshView) ())
{
    this->dices[0] = 0;
    this->dices[1] = 0;
    this->playerIndex = 0;
    this->refreshView = refreshView;

    this->createBoard();
}

void Board::createBoard() {
    this->cases.push_back(new class CornerCase(1957, 777, 0, typeCornerCase::Depart));
    this->cases.push_back(new class Estate(964, 777, 1, "Rue Alix de Vergy", colorEstate::Brown, 60));
    this->cases.push_back(new class DrawCard(898,777,2,typeDrawCard::ComCard));
    this->cases.push_back(new class Estate(832, 777 , 3, "Place des Savoirs", colorEstate::Brown, 60));
    this->cases.push_back(new class Taxe(766, 777, 4, "Impôt sur le revenu", 200));
    this->cases.push_back(new class Gare(700, 777, 5, "Arrêt Grésille", 200));
    this->cases.push_back(new class Estate(634,777, 6, "Rue Dubois", colorEstate::LightBlue, 100));
    this->cases.push_back(new class DrawCard(568,777,7,typeDrawCard::ChanceCard));
    this->cases.push_back(new class Estate(502, 777, 8, "Rue des Marmuzots", colorEstate::LightBlue, 100));
    this->cases.push_back(new class Estate(436, 777, 9, "Rue Vannerie", colorEstate::LightBlue, 120));
    this->cases.push_back(new class CornerCase(343, 777, 10, typeCornerCase::Prison));
    this->cases.push_back(new class Estate(343, 684,11, "Rue Sully", colorEstate::Purple, 140) );
    this->cases.push_back(new class Company(343,618,12,"EDF",150));
    this->cases.push_back(new class Estate(343,552,13,"Boulevard Gabriel", colorEstate::Purple, 140) );
    this->cases.push_back(new class Estate(343,486,14,"Rue d'Auxonne", colorEstate::Purple, 160) );
    this->cases.push_back(new class Gare(343,420,15,"Arrêt Monge",200) );
    this->cases.push_back(new class Estate(343,354,16,"Rue Berbisey", colorEstate::Orange, 180) );
    this->cases.push_back(new class Estate(343,288,17,"Rue Charrue",colorEstate::Orange, 180) );
    this->cases.push_back(new class DrawCard(434,222,18,typeDrawCard::ComCard) );
    this->cases.push_back(new class Estate(343,156,19,"Place Emile Zola", colorEstate::Orange, 200) );
    this->cases.push_back(new class CornerCase(343,63,20,typeCornerCase::Parc) );
    this->cases.push_back(new class Estate(436,63,21, "Rue Claude Cazotte", colorEstate::Red,220) );
    this->cases.push_back(new class DrawCard(502,63,22,typeDrawCard::ChanceCard) );
    this->cases.push_back(new class Estate(568,63,23,"Rue Danton", colorEstate::Red, 220) );
    this->cases.push_back(new class Estate(634,63,24,"Rue de Tivoli",colorEstate::Red, 240) );
    this->cases.push_back(new class Gare(700,63,25,"Arrêt République",200) );
    this->cases.push_back(new class Estate(766,63,26,"Boulevard Thiers",colorEstate::Yellow, 260) );
    this->cases.push_back(new class Estate(832,63,27,"Boulevard Carnot", colorEstate::Yellow, 260) );
    this->cases.push_back(new class Company(898,63,28,"SUEZ",150) );
    this->cases.push_back(new class Estate(964,63,29,"Place du 30 Octobre", colorEstate::Yellow, 280) );
    this->cases.push_back(new class CornerCase(1057,63,30,typeCornerCase::Police) );
    this->cases.push_back(new class Estate(1057,156,31,"Rue de la préfecture", colorEstate::Green, 300) );
    this->cases.push_back(new class Estate(1057,222,32,"Rue des Godrans",colorEstate::Green, 300) );
    this->cases.push_back(new class DrawCard(1057,288,33,typeDrawCard::ComCard) );
    this->cases.push_back(new class Estate(1057,354,34,"Avenue Victor Hugo",colorEstate::Green,320) );
    this->cases.push_back(new class Gare(1057,420,35,"Arrêt Darcy",200) );
    this->cases.push_back(new class DrawCard(1057,486,36,typeDrawCard::ChanceCard) );
    this->cases.push_back(new class Estate(1057,552,37,"Boulevard de la Trémouille",colorEstate::DarkBlue, 350) );
    this->cases.push_back(new class Taxe(1057,618,38,"Galerie de La Fayette",100) );
    this->cases.push_back(new class Estate(1057,684,39, "Rue de la liberté",colorEstate::DarkBlue, 400) );
}

void Board::gameTurn() {
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
            this->onCompanyCase(c);
            break;
        }
        case typeOfCase::CornerCase : {
            class CornerCase* c = static_cast<class CornerCase*>(this->getCaseOfCurrentPlayer());
            std::cout << "The player " << this->getCurrentPlayer()->getName() << " is on a Corner case : " << c->getName() << ", " << c->getType() << std::endl;
            this->onCornerCase(c);
            break;
        }
        case typeOfCase::Draw : {
            class DrawCard* d = static_cast<class DrawCard*>(this->getCaseOfCurrentPlayer());
            std::cout << "The player " << this->getCurrentPlayer()->getName() << " is on a Draw case : " << d->getTypeCase() << std::endl;
            this->onDrawCase(d);
            break;
        }
        case typeOfCase::Estate : {
            class Estate* e = static_cast<class Estate*>(this->getCaseOfCurrentPlayer());
            std::cout << "The player " << this->getCurrentPlayer()->getName() << " is on a Estate case : " << e->getName() << std::endl;
            this->onEstateCase(e);
            break;
        }
        case typeOfCase::Gare : {
            class Gare* g = static_cast<class Gare*>(this->getCaseOfCurrentPlayer());
            std::cout << "The player " << this->getCurrentPlayer()->getName() << " is on a company case : " << g->getName() << std::endl;
            this->onGareCase(g);
            break;
        }
        case typeOfCase::Taxe : {
            class Taxe* t = static_cast<class Taxe*>(this->getCaseOfCurrentPlayer());
            std::cout << "The player " << this->getCurrentPlayer()->getName() << " is on a company case : " << t->getName() << std::endl;
            this->onTaxeCase(t);
            break;
        }
        }
        if (!this->isADouble()) {
            this->nextPlayer();
        }
    }
   *(this->refreshView);
}

bool Board::isADouble() {
    return this->dices[0] == this->dices[1];
}

int Board::getSumDice(void) {
    return this->dices[0] + this->dices [1];
}

Player* Board::getCurrentPlayer() const {
    return this->players[this->playerIndex];
}

Case* Board::getCaseOfCurrentPlayer() const {
    return this->cases[this->getCurrentPlayer()->getLocalisation()];
}

std::vector<Player*> Board::getPlayers() const {
    return this->players;
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
    this->playerIndex += 1;
    if (this->playerIndex - this->players.size() >= 0 ) {
        this->playerIndex = 0;
    }
}

void Board::onEstateCase(class Estate* e) {
    if (e->getOwner() == nullptr) {
        // estate hasn't got a owner. Pop a buying pop-up
    } else {
        if (this->getCurrentPlayer() == e->getOwner()) {
            // the player and the owner is the same
            // check if the player has got all estate with same color.
        } else {
            // the current player needs to pay the owner
            e->payRent(this->getCurrentPlayer());
        }
    }
}

void Board::onGareCase(class Gare *g) {
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

void Board::onCornerCase(class CornerCase *c) {
    // make the right action related by the corner case
    c->actionRelated(this->getCurrentPlayer());
}

void Board::onTaxeCase(class Taxe *t) {
    this->getCurrentPlayer()->looseMoney(t->getPrice());
}

void Board::onCompanyCase(class Company *c) {
    if (c->getOwner() == nullptr) {
        // Company hasn't got a owner. Pop a buying pop-up.
    } else {
        if (this->getCurrentPlayer() != c->getOwner()) {
            // the player and the owner isn't the same
            c->payRent(this->getCurrentPlayer());
        }
    }
}

void Board::onDrawCase(class DrawCard *d) {
    // drawing a card
}
