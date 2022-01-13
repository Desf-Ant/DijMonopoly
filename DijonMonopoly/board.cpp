#include "board.h"

Board::Board()
{
    this->dices[0] = 0;
    this->dices[1] = 0;
    this->playerIndex = 0;
}

void Board::createBoard() {
    // new Estate(0, 0, 1, "Rue Alix de Vergy", "Marron", 80)
    //Estate* e = new Estate();

    //this->cases.push_back(new Estate(0, 0, 1, "Rue Alix de Vergy", colorEstate::Brown, 80));
}

void Board::gameTurn() {
    if (this->getCurrentPlayer()->getIsInJail()) {
        // manage when the player is in jail
    } else {
        this->throwDice();
    }
}

int* Board::getDiceScore() {
    return this->dices;
}

Player* Board::getCurrentPlayer() {
    return this->players[this->playerIndex];
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
