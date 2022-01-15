#include "player.h"

Player::Player()
{
    money = 1500;
    piece = "Lion";
    name = "LeoBot";
    localisation = 0;
}

Player::Player(std::string name, std::string piece, int money) {
    this->name = name;
    this->piece = piece;
    this->money = money;
    this->isInJail = false;
}

void Player::setName(std::string inputName) {
    this->name = inputName;
}

void Player::setPiece(std::string piece) {
    this->piece = piece;
}

void Player::setLocalisation(int numCase) {
    localisation = numCase;
}

void Player::setMoney(int inputArgent) {
    money = inputArgent;
}

void Player::setInJail(bool isInJail) {
    this->isInJail = isInJail;
}

std::string Player::getName() const{
    return this->name ;
}

std::string Player::getPiece() const{
    return this->piece;
}

int Player::getLocalisation() const{
    return this->localisation;
}

int Player::getMoney() const{
    return this->money;
}

bool Player::getIsInJail() const {
    return this->isInJail;
}

void Player::advanceTo(int nb) {
    this->setLocalisation((this->getLocalisation() + nb)%39);
    std::cout << "Player " << this->getName() << "se trouve sur la case n°" << this->getLocalisation();
}

void Player::earnMoney(int money) {
    this->money += money;
    std::cout << "Player " << this->getName() << " earn " << money << " the total is equivalent to " << this->getMoney() ;
}

void Player::looseMoney(int money) {
    this->money -= money;
    if (this->money < 0) {
        // the player loose or needs to sell
    }
}
