#include "Dés.h"
#include <cstdlib>

Dés::Dés(){
    cotes = 6;
}

int Dés::lancerDés(){
    int lancer = 0;
    lancer = rand() % cotes + 1;
    return lancer;
}
