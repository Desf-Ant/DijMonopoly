#include "player.h"

Player::Player()
{
    money = 1500;
    piece = "Lion";
    name = "LeoBot";
    localisation = 0;
    freeJailCard = 0;
}

Player::Player(std::string name, std::string piece, int money) {
    this->name = name;
    this->piece = piece;
    this->money = money;
    this->isInJail = false;
}

Player::~Player() {
    for (int i = 0;i<(int)this->properties.size(); i++) {
        delete this->properties.at(i);
    }
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

void Player::addProperties(Case *c) {
    this->properties.push_back(c);
}

std::string Player::getName() const{
    return this->name ;
}

std::string Player::getPiece() const{
    return this->piece;
}

std::vector<Case*> Player::getProperties() const {
    return this->properties;
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

int Player::getFreeJailCard() const {
    return this->freeJailCard;
}

void Player::addFreeJailCard() {
    this->freeJailCard += 1;
}

void Player::removeFreeJailCard() {
    this->freeJailCard -= 1;
}

void Player::advanceTo(int nb) {
    this->setLocalisation((this->getLocalisation() + nb)%40);
    std::cout << "Player " << this->getName() << " is on the case n°" << this->getLocalisation() <<std::endl;
}

void Player::earnMoney(int money) {
    this->money += money;
    std::cout << "Player " << this->getName() << " earn " << money << " the total is equivalent to " << this->getMoney() << std::endl;
}

void Player::looseMoney(int money) {
    this->money -= money;
    if (this->money < 0) {
        // the player loose or needs to sell
    }
}
