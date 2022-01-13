#include "Taxe.h"

Taxe::Taxe(){
}

Taxe::Taxe(int x, int y, int numero, std::string nom, double prix) {
    this->x = x;
    this->y = y;
    this->numero = numero;
    this->nom = nom;
    this->prix = prix;
}

void Taxe::payer(){
}
