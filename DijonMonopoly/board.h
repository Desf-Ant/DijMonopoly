#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <vector>

#include "player.h"
#include "case.h"
#include "dice.h"
#include "drawCard.h"
#include "taxe.h"
#include "gare.h"
#include "enumHelper.h"
#include "estate.h"
#include "cornercase.h"
#include "company.h"

class Board
{
private:
    std::vector<Player*> players;
    std::vector<Case*> cases;
    int dices[2];
    int playerIndex;
public:
    Board();
    void createBoard(void);
    void gameTurn(void);
    void check(void);

    bool isADouble(void) ;
    int getSumDice(void);
    Player* getCurrentPlayer(void) const ;
    Case* getCaseOfCurrentPlayer(void) const ;

    void throwDice(void);
    void nextPlayer(void);

    void onEstateCase(class Estate* e);
    void onGareCase(class Gare* g);
    void onCornerCase(class CornerCase* c);
    void onTaxeCase(class Taxe* t);
    void onCompanyCase(class Company* c);
    void onDrawCase(class DrawCard* d);
};

#endif // BOARD_H
