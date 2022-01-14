#include "Taxe.h"

Taxe::Taxe(){
}

Taxe::Taxe(int x, int y, int numero, std::string name, double price) {
    this->x = x;
    this->y = y;
    this->numero = numero;
    this->name = name;
    this->price = price;
}

void Taxe::pay(){
}
