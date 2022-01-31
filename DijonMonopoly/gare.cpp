#include "gare.h"

Gare::Gare(){
}

Gare::Gare(int x, int y, int numero, std::string name, double price ,std::string path) {
    this->typeCase = typeOfCase::Gare;
    this->x = x;
    this->y = y;
    this->numero = numero;
    this->name = name;
    this->price = price;
    this->owner = nullptr;
    this->path = path;
}

typeOfCase Gare::getTypeCase() const{
    return this->typeCase;
}

std::string Gare::getName() const {
    return this->name;
}

double Gare::getPrice() const {
    return this->price;
}

Player* Gare::getOwner() const {
    return this->owner;
}

std::string Gare::getPath() const {
    return this->path;
}

void Gare::setOwner(Player *p) {
    this->owner = p;
}

void Gare::buy(){
}

void Gare::bid(){
}

void Gare::payRent(Player *buyer){
    // current player pay rent to the owner
    buyer->looseMoney(this->getPrice());
    this->owner->earnMoney(this->getPrice());
}
