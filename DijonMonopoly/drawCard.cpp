#include "drawCard.h"
#include <stdlib.h>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <fstream>
#include <string>

DrawCard::DrawCard(){
}

DrawCard::DrawCard(int x, int y, int numero, typeDrawCard typeDraw) {
    this->x = x;
    this->y = y;
    this->numero = numero;
    this->type = typeDraw;
    this->RecupFichierchance();
    this->RecupFichiercom();

}

typeDrawCard DrawCard::getTypeDrawCard() const{
    return this->type;
}

std::string DrawCard::RecupFichiercom(){
    QFile filecom ("D:/antoi/Documents/Monopoly/DijMonopoly/DijonMonopoly/cartescom.txt");
    if (!filecom.open (QIODevice::ReadOnly | QIODevice::Text))
        return "NORMAL";

    QTextStream in(&filecom);
    while (!in.atEnd()){
        QString line = in.readLine();
        this->ComCard.push_back(line.toStdString());
        // std::cout << line.toStdString() << std::endl;
    }
    filecom.close();
    return "true";
}

std::string DrawCard::RecupFichierchance(){
    QFile filechance ("D:/antoi/Documents/Monopoly/DijMonopoly/DijonMonopoly/carteschance.txt");
    if (!filechance.open (QIODevice::ReadOnly | QIODevice::Text))
        return "false";

    QTextStream in(&filechance);
    //std::vector <std::string> ChanceCard;
    while (!in.atEnd()){
        QString line = in.readLine();
        this->ChanceCard.push_back(line.toStdString());
        // std::cout << << std::endl;
    }
   // FAUT COPIER std::copy(line.begin(), line.end(),)
    filechance.close();
    //std::cout << ChanceCard.size() << std::endl;
    return "true";
}

std::string DrawCard::DrawChanceCard(){
    this->RecupFichierchance();
    std::cout << this->ChanceCard.size() << std::endl;
    // std::string piocheChance = this->ChanceCard [(int)(rand()*ChanceCard.size())]; //BUG FONCTIONNE PAS ICI
    std::string piocheChance = this->ChanceCard.at(14);
    // std::cout << piocheChance << std::endl;
    return piocheChance;
}

std::string DrawCard::DrawComCard(){
    this->RecupFichiercom();
    //std::string piocheCom = ComCard [(int)(rand()*ComCard.size())];
    std::string piocheCom = this->ComCard.at(14);
    //std::cout << piocheCom << std::endl;
    return piocheCom;
}
