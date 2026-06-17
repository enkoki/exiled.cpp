#include "Player.h"
#include <iomanip>
#include <iostream>

Player::Player() : Character() {
    exp = 0;
    expToLevel = 100;
    gold = 0;
    className = "Novice";
}
 
Player::Player(std::string name, int hp, int attack, int defense, int level, int exp, int gold)
    : Character(name, hp, attack, defense, level) {
    this->exp = exp;
    this->gold = gold;
    this->expToLevel = 100;
    this->className = "Novice";
}

Player::Player(const Player& other) : Character(other) {
    exp = other.exp;
    expToLevel = other.expToLevel;
    gold = other.gold;
    className = other.className;
}

Player::~Player() {
    std::cout << name << " the " << className << " has left the game.\n";
}

void Player::attackAction(){
    std::cout << name << " the" << className << " attacks for " << attack << " damage.\n";
}

void Player::displayInfo() {
    std::cout << "\n╔══════════════════════════════════════════╗\n";
    std::cout << "║                                          ║\n";
    std::cout << "║  Name  : " << std::left << std::setw(13) << name 
              << "Class  : " << std::setw(10) << className << "║\n";
    std::cout << "║  Level : " << std::left << std::setw(13) << level 
              << "EXP    : " << std::setw(10) << (std::to_string(exp) + "/" + std::to_string(expToLevel)) << "║\n";
    std::cout << "║                                          ║\n";
    std::cout << "╠══════════════════════════════════════════╣\n";
    std::cout << "║                                          ║\n";
    std::cout << "║  HP      : " << std::setw(30) << (std::to_string(hp) + "/" + std::to_string(maxHp)) << "║\n";
    std::cout << "║  Attack  : " << std::setw(30) << attack << "║\n";
    std::cout << "║  Defense : " << std::setw(30) << defense << "║\n";
    std::cout << "║  Gold    : " << std::setw(30) << gold << "║\n";
    std::cout << "║                                          ║\n";
    std::cout << "╚══════════════════════════════════════════╝\n";
}

int Player::getExp(){ return exp; }
int Player::getExpToLevel(){ return expToLevel; }
int Player::getGold(){ return gold; }
 
void Player::gainExperience(int amt) {
    exp += amt;
    std::cout << name << " gained " << amt << " EXP!\n";
    if (exp >= expToLevel) {
        levelUp();
    }
}
 
void Player::levelUp() {
    level++;
    exp = 0;
    expToLevel = expToLevel * 1.5;
    maxHp += 10;
    hp = maxHp;
    attack += 2;
    defense += 1;
    std::cout << name << " leveled up! Now level " << level << "!\n";
}



