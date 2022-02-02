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
    ~Company();
    Company(int x, int y, int numero, std::string name, double price, std::string path);

    typeOfCase getTypeCase (void) const;
    std::string getName(void) const;
    double getPrice(void) const;
    Player* getOwner(void) const;
    std::string getPath(void) const;
    int getRent(int sumDice) const ;

    void setOwner(Player* p);

    void buy();
    void bid();
    void payRent(Player* p);
    void payRent(Player* buyer, int sumDice);
};

#endif // COMPANY_H
