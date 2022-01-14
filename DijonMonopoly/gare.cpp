#include "gare.h"

Gare::Gare(){
}

Gare::Gare(int x, int y, int numero, std::string name, double price) {
    this->x = x;
    this->y = y;
    this->numero = numero;
    this->name = name;
    this->price = price;
}

std::string Gare::getName() {
    return this->name;
}

Player* Gare::getOwner(){
    return this->owner;
}
double Gare::getPrice() {
    return this->price;
}

int Gare::getHouse() {
    return this->house;
}

void Gare::setOwner(Player* newOwner) {
    this->owner = newOwner;
}

void Gare::setHouse(int numberHouse){
    this->house = numberHouse;
}

void buy() {
}

void bid() {
}

void payRent(){
}
