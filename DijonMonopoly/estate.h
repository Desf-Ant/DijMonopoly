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
    std::string path;
    colorEstate color;
    std::vector<int> rents;
    double price;
    int house;
public:
    Estate();
    ~Estate();
    Estate(int x, int y, int numero, std::string name, colorEstate color, double price, std::vector<int> rents, std::string path);

    void checkRents(void);

    typeOfCase getTypeCase(void) const;
    std::string getName(void) const;
    colorEstate getColor(void) const;
    int getRent(void) const;
    Player* getOwner(void) const;
    double getPrice(void) const;
    int getHouse(void) const;
    std::string getPath(void) const;

    void setOwner(Player* newOwner);
    void setHouse(int numberHouse);

    void buy(Player* owner);
    void bid();
    void payRent(Player* buyer);
};

#endif // ESTATE_H
