#include "Warrior.h"
#include <iostream>

Warrior::Warrior() : Player() {
    rage = 0;
}

Warrior::Warrior(std::string name, int hp, int attack, int defense, int level, int exp, int gold, int rage)
    : Player(name, hp, attack, defense, level, exp, gold) {
    this->rage = rage;
}

Warrior::Warrior(const Warrior& other) : Player(other) {
    rage = other.rage;
}

Warrior::~Warrior() {
    std::cout << name << " the Warrior falls in battle.\n";
}

void Warrior::attackAction() {
    if (rage >= 50) {
        std::cout << name << " unleashes a POWER ATTACK for " << attack * 2 << " damage! Rage consumed.\n";
        rage = 0;
    } else {
        std::cout << name << " swings their sword for " << attack << " damage!\n";
        buildRage();
    }
}

void Warrior::displayInfo() {
    Player::displayInfo();
    std::cout << "Rage: " << rage << "/100\n";
}

int Warrior::getRage(){ return rage; }

void Warrior::buildRage() {
    rage += 10;
    if (rage > 100) rage = 100;
    std::cout << name << " builds rage! Rage: " << rage << "/100\n";
}