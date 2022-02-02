#ifndef DRAWCARD_H
#define DRAWCARD_H
#include <string>
#include <vector>
#include "case.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <fstream>
#include <string>
#include <math.h>

#include "enumHelper.h"
#include "popupcard.h"

class DrawCard : public Case {
protected:
    std::vector <std::string> ComCard;
    std::vector <std::string> ChanceCard;
    typeDrawCard type;
    //typeOfCase typeCase;

public:
    DrawCard();
    DrawCard(int x, int y, int numero, typeDrawCard typeDraw);

    typeOfCase getTypeCase(void) const;
    typeDrawCard getTypeDrawCard(void) const;
    void draw(typeDrawCard typeDraw);
    std::string RecupFichiercom();
    std::string RecupFichierchance();
    std::string DrawChanceCard ();
    std::string DrawComCard();
};

#endif // DRAWCARD_H
