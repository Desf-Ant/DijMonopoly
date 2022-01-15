#ifndef CORNERCASE_H
#define CORNERCASE_H
#include <string>

#include "iostream"
#include "case.h"

#include "enumHelper.h"

class CornerCase : public Case
{
private:
    typeCornerCase type;
public:
    CornerCase();
    CornerCase(int x, int y, int numero, typeCornerCase typeCorner);

    typeOfCase getTypeCase(void) const;
    typeCornerCase getType(void) const;
    std::string getName(void) const;

    void actionRelated(Player* p);
};

#endif // CORNERCASE_H
