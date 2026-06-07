#include "Player.h"
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
    std::cout << name << "the" << className << " attacks for " << attack << " damage.\n";
}

void Player::displayInfo() {
    std::cout << "=== Player Info ===\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Class: " << className << "\n";
    std::cout << "HP: " << hp << "/" << maxHp << "\n";
    std::cout << "Attack: " << attack << "\n";
    std::cout << "Defense: " << defense << "\n";
    std::cout << "Level: " << level << "\n";
    std::cout << "EXP: " << exp << "/" << expToLevel << "\n";
    std::cout << "Gold: " << gold << "\n";
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



