#ifndef CASE_H
#define CASE_H

#include <QPointF>

#include "enumHelper.h"
#include "player.h"

class Case
{
protected :
    int numero;
    int x;
    int y;
    typeOfCase typeCase;
    Player* playerOnIt;
public:
    Case();
    typeOfCase getTypeCase(void) const;
    QPointF getCoordCenter(void) const;
};

#endif // CASE_H
