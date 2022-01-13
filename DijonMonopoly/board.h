#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <vector>

#include "player.h"
#include "case.h"
#include "dice.h"
#include "estate.h"

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

    int* getDiceScore(void) ;
    Player* getCurrentPlayer(void) ;

    void throwDice(void);
    void nextPlayer(void);
};

#endif // BOARD_H
