#ifndef PIOCHE_H
#define PIOCHE_H
#include <string>
#include <vector>
#include "case.h"

typedef enum typeDrawCard { ComCard, ChanceCard } typeDrawCard;

class DrawCard : public Case {
protected:
    std::vector <std::string> ComCard;
    std::vector <std::string> ChanceCard;
    typeDrawCard type;

public:
    DrawCard();
    DrawCard(int x, int y, int numero, typeDrawCard typeDraw);

    void Draw(typeDrawCard typeDraw);
};

#endif // PIOCHE_H
