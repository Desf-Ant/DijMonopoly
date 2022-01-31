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

class MainWindow;

class Board
{
private:
    std::vector<Player*> players;
    std::vector<Case*> cases;
    std::vector<int> dices;
    double playerIndex;
    //void (*refreshView) ();
    //void (MainWindow::*refreshView)();
    //void* refreshView;
public:
    Board();
    //Board(void (*refreshView) ());
    //Board(void (MainWindow::*refreshView)());
    void createBoard(void);
    void gameTurn(MainWindow* w);
    void check(void);

    bool isADouble(void) const;
    int getSumDice(void) const;
    double getPlayerIndex(void) const;
    int getDice1(void);
    int getDice2(void);
    Player* getCurrentPlayer(void) ;
    Case* getCaseOfCurrentPlayer(void);
    std::vector<Player*> getPlayers(void) const;
    Case* getCaseAt(int index);

    void setPlayers (std::vector<Player*> p);
    void addPlayer (Player* p);

    void throwDice(void);
    void nextPlayer(void);
    void currentPlayerBuyCurrentEstate(void);

    void onEstateCase(class Estate* e, MainWindow* w);
    void onGareCase(class Gare* g, MainWindow* w);
    void onCornerCase(class CornerCase* c, MainWindow* w);
    void onTaxeCase(class Taxe* t, MainWindow* w);
    void onCompanyCase(class Company* c, MainWindow* w);
    void onDrawCase(class DrawCard* d, MainWindow* w);

    void refreshViewDelegate(MainWindow* w);
    void popUpBuyEstate(MainWindow* w, class Estate* e);

    void popUpPayRent(MainWindow* w, class Estate* e, class Player* buyer);
};

#endif // BOARD_H
