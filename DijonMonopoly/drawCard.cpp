#include "drawCard.h"
#include <stdlib.h>


DrawCard::DrawCard(){
}

DrawCard::DrawCard(int x, int y, int numero, typeDrawCard typeDraw) {
    this->typeCase = typeOfCase::Draw;
    this->x = x;
    this->y = y;
    this->numero = numero;
    this->type = typeDraw;
    this->RecupFichierchance();
    this->RecupFichiercom();
}

typeOfCase DrawCard::getTypeCase(void) const {
    return this->typeCase;
}

typeDrawCard DrawCard::getTypeDrawCard() const{
    return this->type;
}

std::string DrawCard::RecupFichiercom(){
    auto current = QOperatingSystemVersion::current();
    QString beginPath = "";
    if (current >= QOperatingSystemVersion::MacOSSierra) {
        std::cout << "system Mac" << current.currentType() << std::endl;
        beginPath = "../../../../";
    }
    if (current >= QOperatingSystemVersion::Windows10) {
        std::cout << "system Win" << std::endl;
        beginPath = "../";
    }
    QFile filecom (beginPath+"DijonMonopoly/cartescom.txt");
    if (!filecom.open (QIODevice::ReadOnly | QIODevice::Text))
        return "NORMAL";

    QTextStream in(&filecom);
    while (!in.atEnd()){
        QString line = in.readLine();
        this->ComCard.push_back(line.toStdString());
    }
    filecom.close();
    return "true";
}

std::string DrawCard::RecupFichierchance(){
    auto current = QOperatingSystemVersion::current();
    QString beginPath = "";
    if (current >= QOperatingSystemVersion::MacOSSierra) {
        std::cout << "system Mac" << current.currentType() << std::endl;
        beginPath = "../../../../";
    }
    if (current >= QOperatingSystemVersion::Windows10) {
        std::cout << "system Win" << std::endl;
        beginPath = "../";
    }
    QFile filechance (beginPath+"DijonMonopoly/carteschance.txt");
    if (!filechance.open (QIODevice::ReadOnly | QIODevice::Text))
        return "false";

    QTextStream in(&filechance);
    while (!in.atEnd()){
        QString line = in.readLine();
        this->ChanceCard.push_back(line.toStdString());
    }
   // FAUT COPIER std::copy(line.begin(), line.end(),)
    filechance.close();
    return "true";
}

void DrawCard::draw(typeDrawCard typeDraw) {
    PopUpCard* pop = new PopUpCard(nullptr, typeDraw);
    pop->show();
}

std::string DrawCard::DrawChanceCard(){
    this->RecupFichierchance();
    std::cout << this->ChanceCard.size() << std::endl;
    std::string piocheChance = this->ChanceCard.at((int)(arc4random()%ChanceCard.size()));
    std::cout << piocheChance << std::endl;
    return piocheChance;
}

std::string DrawCard::DrawComCard(){
    this->RecupFichiercom();
    std::string piocheCom = this->ComCard.at((int)(arc4random()%ChanceCard.size()));
    std::cout << piocheCom << std::endl;
    return piocheCom;
}
