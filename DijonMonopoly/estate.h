#ifndef ESTATE_H
#define ESTATE_H

#include <string>
#include "case.h"
#include "player.h"

typedef enum colorEstate {Brown, LightBlue, Purple, Orange, Red, Yellow, Green, DarkBlue} colorEstate ;

class Estate : public virtual Case
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

    std::string getName();
    colorEstate getColor();
    Player* getOwner();
    double getPrice();
    int getHouse();

    void setOwner(Player* newOwner);
    void setHouse(int numberHouse);

    void buy();
    void bid();
    void payRent();
};

#endif // ESTATE_H
