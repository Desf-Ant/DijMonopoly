#ifndef COMPANY_H
#define COMPANY_H

#include <string>

#include "enumHelper.h"
#include "case.h"
#include "player.h"

class Company : public Case
{
private:
    std::string name;
    Player* owner;
    double price;
public:
    Company();
    Company(int x, int y, int numero, std::string name, double price);

    typeOfCase getTypeCase (void) const;
    std::string getName(void) const;
    double getPrice(void) const;
    Player* getOwner(void) const;

    void setOwner(Player* p);

    void buy();
    void bid();
    void payRent(Player* p);
};

#endif // COMPANY_H
