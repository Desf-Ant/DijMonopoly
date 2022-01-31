#include "case.h"

Case::Case()
{

}

typeOfCase Case::getTypeCase() const{
    return this->typeCase;
}

QPointF Case::getCoordCenter() const {
    return QPointF(this->x,this->y);
}
