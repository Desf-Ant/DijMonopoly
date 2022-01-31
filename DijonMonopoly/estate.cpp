#include "estate.h"

Estate::Estate()
{

}

Estate::Estate(int x, int y, int numero, std::string name, colorEstate color, double price, std::vector<int> rents, std::string path) {
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
    this->path = path;
    for (int i=0; i<(int)rents.size();i++) {
        this->rents.push_back(rents.at(i));
    }
}

void Estate::checkRents() {
    for (int i=0; i<(int)this->rents.size();i++) {
        std::cout << this->rents.at(i) << std::endl;
    }
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

int Estate::getRent() const {
    //this->checkRents();
    return this->rents.at(this->getHouse());
}

int Estate::getHouse() const{
    return this->house;
}

std::string Estate::getPath() const {
    return this->path;
}

void Estate::setOwner(Player* newOwner) {
    this->owner = newOwner;
}

void Estate::setHouse(int numberHouse){
    this->house = numberHouse;
}

void Estate::buy(Player* owner) {
    std::cout << "argent " << std::to_string(owner->getMoney()) <<  std::endl;
    this->setOwner(owner);
    owner->looseMoney(this->getPrice());
    owner->addProperties(this);
    std::cout << "argent 1 " << std::to_string(owner->getMoney()) <<  std::endl;
}

void Estate::bid() {
}

void Estate::payRent(Player* buyer){
    // current player pay rent to the owner
    buyer->looseMoney(this->getRent());
    this->owner->earnMoney(this->getRent());
}
