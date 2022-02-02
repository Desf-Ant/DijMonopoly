#ifndef DRAWCARD_H
#define DRAWCARD_H
#include <string>
#include <vector>
#include "case.h"

class DrawCard : public Case {
protected:
    std::vector <std::string> ComCard;
    std::vector <std::string> ChanceCard;
    typeDrawCard type;
    typeOfCase typeCase;

public:
    DrawCard();
    DrawCard(int x, int y, int numero, typeDrawCard typeDraw);

    typeOfCase getTypeCase(void) const;
    typeDrawCard getTypeDrawCard(void) const;
    void Draw(typeDrawCard typeDraw);
    std::string RecupFichiercom();
    std::string RecupFichierchance();
    std::string DrawChanceCard ();
    std::string DrawComCard();
};

#endif // DRAWCARD_H
