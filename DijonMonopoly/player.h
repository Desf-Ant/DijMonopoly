#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

class Case;

class Player
{
private:
    std::string name;
    std::string piece;
    int money;
    int localisation;
    std::vector<Case*> properties;
    bool isInJail;
public:
    Player();
    Player(std::string name, std::string piece, int argent);

    void setName(std::string inputName);
    void setPiece(std::string piece);
    void setLocalisation(int numCase);
    void setMoney(int inputMoney);
    void setInJail(bool isInJail);

    std::string getName(void) const;
    std::string getPiece(void) const;
    int getMoney(void) const;
    int getLocalisation(void) const;
    bool getIsInJail(void) const;

    void advanceTo(int nb);
    void earnMoney(int money);
    void looseMoney(int money);
};

#endif // PLAYER_H
