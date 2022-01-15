#ifndef ESTATE_H
#define ESTATE_H

#include <string>
#include "case.h"
#include "player.h"
#include "enumHelper.h"

class Estate : public Case
{
private:
    std::string name;
    colorEstate color;
    Player* owner;
    double price;
    int house;
public:
    Estate();
    Estate(int x, int y, int numero, std::string name, colorEstate color, double price);

    typeOfCase getTypeCase(void) const;
    std::string getName() const;
    colorEstate getColor() const;
    Player* getOwner() const;
    double getPrice() const;
    int getHouse() const;

    void setOwner(Player* newOwner);
    void setHouse(int numberHouse);

    void buy();
    void bid();
    void payRent(Player* buyer);
};

#endif // ESTATE_H
