#ifndef CASE_H
#define CASE_H

#include <QPointF>
#include <string>

#include "enumHelper.h"
#include "player.h"

class Case
{
protected :
    int numero;
    int x;
    int y;
    std::string name;
    typeOfCase typeCase;
    Player* playerOnIt;
    Player* owner;
    std::string path;
    colorEstate color;
    std::vector<int> rents;
    double price;
    int house;
public:
    Case();
    virtual ~Case();
    typeOfCase getTypeCase(void) const;
    QPointF getCoordCenter(void) const;
    virtual std::string getName(void) const;
    virtual colorEstate getColor(void) const;
    virtual int getRent(void) const;
    virtual int getRent(int sumDice) const;
    virtual Player* getOwner(void) const;
    virtual double getPrice(void) const;
    virtual int getHouse(void) const;
    virtual std::string getPath(void) const;
    virtual void actionRelated(Player* p);

    virtual void setOwner(Player* newOwner);
    virtual void setHouse(int numberHouse);

    virtual void buy(Player* owner);
    virtual void payRent(Player* buyer);
    virtual void payRent(Player* buyer, int sumDice);
};

#endif // CASE_H
