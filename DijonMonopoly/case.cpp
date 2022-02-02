#include "case.h"

Case::Case()
{

}

typeOfCase Case::getTypeCase() const{
    return this->typeCase;
}

QPointF Case::getCoordCenter() const {
    return QPointF(this->x,this->y);
}

std::string Case::getName() const{
    return this->name;
}

colorEstate Case::getColor(void) const {
    return this->color;
}
int Case::getRent(void) const {
    if (this->rents.size() > 0)
        return this->rents.at(0);
    return 0;
}
Player* Case::getOwner(void) const {
    return this->owner;
}
double Case::getPrice(void) const {
    return this->price;
}
int Case::getHouse(void) const{
    return this->house;
}
std::string Case::getPath(void) const{
    return this->path;
}

void Case::setOwner(Player* newOwner){
    this->owner = newOwner;
}
void Case::setHouse(int numberHouse) {
    this->house = numberHouse;
}

int Case::getRent(int sumDice) const {
    return 0*sumDice;
}

void Case::buy(Player* owner) {

}

void Case::payRent(Player* buyer){

}

void Case::payRent(Player* buyer, int sumDice) {

}

void Case::actionRelated(Player* p) {

}
