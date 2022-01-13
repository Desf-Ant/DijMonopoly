#include "estate.h"

Estate::Estate()
{

}

Estate::Estate(int x, int y, int numero, std::string name, colorEstate, double price) {
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

std::string Estate::getName() {
    return this->name;
}
colorEstate Estate::getColor(){
    return this->color;
}
Player* Estate::getOwner(){
    return this->owner;
}
double Estate::getPrice() {
    return this->price;
}

int Estate::getHouse() {
    return this->house;
}

void Estate::setOwner(Player* newOwner) {
    this->owner = newOwner;
}

void Estate::setHouse(int numberHouse){
    this->house = numberHouse;
}

void buy() {

}

void bid() {

}

void payRent(){

}
