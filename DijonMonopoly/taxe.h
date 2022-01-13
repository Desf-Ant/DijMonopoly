#ifndef TAXE_H
#define TAXE_H

#include "case.h"
#include <string>
#include "player.h"

class Taxe : public virtual Case
{

private:
    std::string nom;
    double prix;

public:
    Taxe();
    Taxe(int x, int y, int numero, std::string nom, double prix);

    void payer();
};

#endif // TAXE_H
