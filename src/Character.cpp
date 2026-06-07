#include "Character.h"
#include <iostream>

// Default constructor
Character::Character() {
    name = "Unknown";
    hp = 100;
    maxHp = 100;
    attack = 10;
    defense = 5;
    level = 1;
}

//Paramter Constructor
Character::Character(std::string name, int hp, int attack, int defense, int level) {
    this->name = name;
    this->hp = hp;
    this->maxHp = hp;
    this->attack = attack;
    this->defense = defense;
    this->level = level;
}

//Copy Constructor
Character::Character(const Character& other) {
    name = other.name;
    hp = other.hp;
    maxHp = other.maxHp;
    attack = other.attack;
    defense = other.defense;
    level = other.level;
}

Character::~Character() {
    std::cout << name << " has been removed from the game.\n";
}

//Virtual Functions
void Character::attackAction() {
    std::cout << name << " attacks for " << attack << " damage!\n";
}
 
void Character::displayInfo() {
    std::cout << "Name: " << name << "\n";
    std::cout << "HP: " << hp << "/" << maxHp << "\n";
    std::cout << "Attack: " << attack << "\n";
    std::cout << "Defense: " << defense << "\n";
    std::cout << "Level: " << level << "\n";
}
 
// Getters
std::string Character::getName(){ return name; }
int Character::getHp(){ return hp; }
int Character::getMaxHp(){ return maxHp; }
int Character::getAttack(){ return attack; }
int Character::getDefense(){ return defense; }
int Character::getLevel(){ return level; }
 
bool Character::isAlive() {
    return hp > 0;
}
 
void Character::takeDamage(int damage) {
    int actualDamage = damage - defense;
    if (actualDamage < 1) actualDamage = 1;
    hp -= actualDamage;
    if (hp < 0) hp = 0;
    std::cout << name << " took " << actualDamage << " damage! HP: " << hp << "/" << maxHp << "\n";
}


