#include "cornercase.h"

CornerCase::CornerCase()
{

}

CornerCase::CornerCase(int x, int y, int numero, typeCornerCase typeCorner) {
    this->x = x;
    this->y = y;
    this->numero = numero;
    this->type = typeCorner;
}

typeCornerCase CornerCase::getType() const{
    return this->type;
}

std::string CornerCase::getName() const{
    switch(this->type) {
        case typeCornerCase::Depart :
            return "Départ";
        case typeCornerCase::Police :
            return "Les Hendecks";
        case typeCornerCase::Parc :
            return "Parc de la Colombière";
        case typeCornerCase::Prison :
            return "La zonzon";
        default:
            return "";
    }
}

void CornerCase::actionRelated (void) {
    switch(this->type) {
        case typeCornerCase::Depart :
            std::cout << "Vous recevez le double ! 400";
            break;
        case typeCornerCase::Police :
            std::cout << "Vous allez en prison sans passer par la case départ";
            break;
        case typeCornerCase::Parc :
            std::cout << "Vous pouvez flâner au parc, tranquillement";
            break;
        case typeCornerCase::Prison :
            std::cout << "Vous rendez visite aux criminels";
            break;
    }
}
