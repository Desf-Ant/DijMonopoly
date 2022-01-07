#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>
#include <vector>

class Joueur{

protected:
    std::string nom;
    std::string piece;
    int argent;
    int localisation;

public:
    Joueur();
    Joueur(int argent);

    void setNom(std::string inputNom);
    void setPiece (std::string piece);
    void setLocalisation (int numCase);
    void setArgent (int inputArgent);

    std::string getNom();
    std::string getPiece();
    int getArgent();
    int getLocalisation();

};

#endif // JOUEUR_H
