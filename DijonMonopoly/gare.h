#ifndef GARE_H
#define GARE_H
#include "case.h"
#include <string>
#include "player.h"

class Gare : public virtual Case
{

private:
    std::string nom;
    Player proprietaire;
    double prix;

public:
    Gare();
    Gare(int x, int y, int numero, std::string nom, double prix);

    void acheter();
    void enchere();
    void payer();
};

#endif // GARE_H
