#include "company.h"

Company::Company()
{

}

Company::Company(int x, int y, int numero, std::string name, double price) {
    this->typeCase = typeOfCase::Company;
    this->x = x;
    this->y = y;
    this->numero = numero;
    this->name = name;
    this->price = price;
    this->owner = nullptr;
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

void Company::setOwner(Player *p) {
    this->owner = p;
}

void Company::buy() {

}

void Company::bid() {

}

void Company::payRent(Player* p) {
    p->looseMoney(this->getPrice());
    this->getOwner()->earnMoney(this->getPrice());
}
