#include "joueur.h"

Joueur::Joueur(){
    argent = 1500;
    piece = "Lion";
    nom = "LéoBOT";
    localisation = 0;
}

Joueur::Joueur(int argent){
    argent = argent;
    localisation = 0;
    nom="LéomBOT";
}

void Joueur::setNom(std::string inputNom){
    nom = inputNom;
}

void Joueur::setPiece(std::string piece){
    piece = piece;
}

void Joueur::setLocalisation(int numCase){
    localisation = numCase;
}

void Joueur::setArgent(int inputArgent){
    argent = inputArgent;
}

std::string Joueur::getNom(){
    return nom;
}

std::string Joueur::getPiece(){
    return piece;
}

int Joueur::getLocalisation(){
    return localisation;
}

int Joueur::getArgent(){
    return argent = argent;
}
