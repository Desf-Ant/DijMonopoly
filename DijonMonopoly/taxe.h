#ifndef TAXE_H
#define TAXE_H

#include "case.h"
#include <string>
#include "player.h"

class Taxe : public Case
{

private:
    std::string name;
    double price;

public:
    Taxe();
    Taxe(int x, int y, int numero, std::string name, double price);

    typeOfCase getTypeCase(void) const;
    std::string getName(void) const;
    int getPrice(void) const;

    void setOwner(Player* p);

    void payer();
};

#endif // TAXE_H
