#include "dice.h"
#include <cstdlib>

Dice::Dice()
{
    sides = 6;
}

static int Dice::throwDice(){
    int t = 0;
    t = rand()%this->sides + 1;
    return t;
}
