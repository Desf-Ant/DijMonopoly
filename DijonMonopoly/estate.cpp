#include "estate.h"

Estate::Estate()
{

}

Estate::Estate(int x, int y, int numero, std::string name, colorEstate color, double price) {
    this->typeCase = typeOfCase::Estate;
    this->owner = nullptr;
    this->house = 0;
    this->playerOnIt = nullptr;
    this->x = x;
    this->y = y;
    this->numero = numero;
    this->name = name;
    this->color = color;
    this->price = price;
}

typeOfCase Estate::getTypeCase() const {
    return this->typeCase;
}
std::string Estate::getName() const{
    return this->name;
}
colorEstate Estate::getColor() const{
    return this->color;
}
Player* Estate::getOwner() const{
    return this->owner;
}
double Estate::getPrice() const {
    return this->price;
}

int Estate::getHouse() const{
    return this->house;
}

void Estate::setOwner(Player* newOwner) {
    this->owner = newOwner;
}

void Estate::setHouse(int numberHouse){
    this->house = numberHouse;
}

void Estate::buy() {
}

void Estate::bid() {
}

void Estate::payRent(Player* buyer){
    // current player pay rent to the owner
    buyer->looseMoney(this->getPrice());
    this->owner->earnMoney(this->getPrice());
}
