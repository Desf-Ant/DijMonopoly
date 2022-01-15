#ifndef GARE_H
#define GARE_H
#include <string>
#include "case.h"
#include "player.h"

class Gare : public Case
{

private:
    std::string name;
    Player* owner;
    double price;

public:
    Gare();
    Gare(int x, int y, int numero, std::string name, double price);

    typeOfCase getTypeCase(void) const;
    std::string getName(void) const;
    int getPrice(void) const;
    Player* getOwner(void) const;

    void setOwner(Player* p);

    void buy();
    void bid();
    void payRent(Player* buyer);
};

#endif // GARE_H
