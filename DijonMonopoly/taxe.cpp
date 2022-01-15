#include "taxe.h"

Taxe::Taxe(){
}

Taxe::Taxe(int x, int y, int numero, std::string name, double price) {
    this->typeCase = typeOfCase::Taxe;
    this->x = x;
    this->y = y;
    this->numero = numero;
    this->name = name;
    this->price = price;
}

typeOfCase Taxe::getTypeCase() const{
    return this->typeCase;
}

std::string Taxe::getName() const {
    return this->name;
}

int Taxe::getPrice() const {
    return this->price;
}

void Taxe::payer(){
}
