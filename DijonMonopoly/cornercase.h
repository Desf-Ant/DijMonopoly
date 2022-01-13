#ifndef CORNERCASE_H
#define CORNERCASE_H
#include <string>

#include "iostream"
#include "case.h"

typedef enum typeCornerCase { Depart, Prison, Parc, Police } typeCornerCase;

class CornerCase : public Case
{
private:
    typeCornerCase type;
public:
    CornerCase();
    CornerCase(int x, int y, int numero, typeCornerCase typeCorner);

    typeCornerCase getType(void) const;
    std::string getName(void) const;

    void actionRelated(void);
};

#endif // CORNERCASE_H
