#ifndef DRAWCARD_H
#define DRAWCARD_H
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
    std::string RecupFichiercom();
    std::string RecupFichierchance();
    std::string DrawChanceCard ();
};

#endif // DRAWCARD_H
