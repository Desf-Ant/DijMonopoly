#ifndef PIOCHE_H
#define PIOCHE_H
#include <string>
#include <vector>
#include "case.h"

class Pioche : public Case{
protected:
    std::vector <std::string> cartesCommu;

    std::vector <std::string> cartesChance;

    int taille = 16;

public:
    void Piocher();

};

#endif // PIOCHE_H
