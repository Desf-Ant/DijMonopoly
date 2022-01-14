#ifndef GARE_H
#define GARE_H
#include <string>
#include "case.h"
#include "player.h"

class Gare : public virtual Case
{

private:
    std::string name;
    Player* owner;
    double price;
    int house;

public:
    Gare();
    Gare(int x, int y, int numero, std::string name, double price);

    std::string getName();
    Player* getOwner();
    double getPrice();
    int getHouse();

    void setOwner(Player* newOwner);
    void setHouse(int numberHouse);

    void buy();
    void bid();
    void payRent();
};

#endif // GARE_H
