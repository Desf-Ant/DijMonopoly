#include "board.h"

Board::Board()
{
    this->dices[0] = 0;
    this->dices[1] = 0;
    this->playerIndex = 0;

    this->createBoard();
}

void Board::createBoard() {
    this->cases.push_back(new class CornerCase(0, 0, 0, typeCornerCase::Depart));
    this->cases.push_back(new class Estate(0, 0, 1, "Rue Alix de Vergy", colorEstate::Brown, 60));
    this->cases.push_back(new class DrawCard());
    this->cases.push_back(new class Estate(0, 0, 3, "Place des Savoirs", colorEstate::Brown, 60));
    this->cases.push_back(new class Taxe(0, 0, 4, "Impôt sur le revenu", 200));
    this->cases.push_back(new class Gare(0, 0, 5, "Arrêt Grésille", 200));
    this->cases.push_back(new class Estate(0, 0, 6, "Rue Dubois", colorEstate::LightBlue, 100));
    this->cases.push_back(new class DrawCard());
    this->cases.push_back(new class Estate(0, 0, 8, "Rue des Marmuzots", colorEstate::LightBlue, 100));
    this->cases.push_back(new class Estate(0, 0, 9, "Rue Vannerie", colorEstate::LightBlue, 120));
    this->cases.push_back(new class CornerCase(0, 0, 10, typeCornerCase::Prison));
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

void Board::throwDice() {
    Dice d = Dice();
    this->dices[0] = d.throwDice();
    this->dices[1] = d.throwDice();
}

void Board::nextPlayer() {
    this->playerIndex += 1;
    if (this->playerIndex - this->players.size() >= 0 )
        this->playerIndex = 0;
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
