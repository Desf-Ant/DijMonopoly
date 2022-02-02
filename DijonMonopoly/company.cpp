#include "company.h"

Company::Company()
{

}

Company::Company(int x, int y, int numero, std::string name, double price, std::string path) {
    this->typeCase = typeOfCase::Company;
    this->x = x;
    this->y = y;
    this->numero = numero;
    this->name = name;
    this->price = price;
    this->owner = nullptr;
    this->path = path;
    this->rents = {4,10};
    this->house = 0;
}

typeOfCase Company::getTypeCase () const {
    return this->typeCase;
}

std::string Company::getName() const {
    return this->name;
}

double Company::getPrice() const {
    return this->price;
}

Player* Company::getOwner() const {
    return this->owner;
}

std::string Company::getPath() const {
    return this->path;
}

int Company::getRent(int sumDice) const {
    return this->rents.at(this->house)*sumDice;
}

void Company::setOwner(Player *p) {
    this->owner = p;
}

void Company::buy() {

}

void Company::bid() {

}

void Company::payRent(Player *p) {

}

void Company::payRent(Player* buyer, int sumDice) {
    buyer->looseMoney(this->getRent(sumDice));
    this->getOwner()->earnMoney(this->getRent(sumDice));
}
