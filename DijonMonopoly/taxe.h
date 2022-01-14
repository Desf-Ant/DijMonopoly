#ifndef TAXE_H
#define TAXE_H

#include "case.h"
#include <string>
#include "player.h"

class Taxe : public virtual Case
{

private:
    std::string name;
    double price;

public:
    Taxe();
    Taxe(int x, int y, int numero, std::string name, double price);

    void pay();
};

#endif // TAXE_H
