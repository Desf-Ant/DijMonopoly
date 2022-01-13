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
