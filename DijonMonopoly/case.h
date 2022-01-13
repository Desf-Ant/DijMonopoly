#ifndef CASE_H
#define CASE_H

class Player;

class Case
{
protected :
    int numero;
    int x;
    int y;
    Player* playerOnIt;
public:
    Case();
};

#endif // CASE_H
