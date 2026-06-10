#include "Samurai.h"
#include "Player.h"
#include <iostream>
#include <string>

Samurai::Samurai(){
    bleed = 0;
};

Samurai::Samurai(std::string name, int hp, int attack, int defense, int level, int exp, int gold, int bleed)
    : Player(name, hp, attack, defense, level, exp, gold){
        this->bleed = bleed;
};

Samurai::Samurai(const Samurai& other) : Player(other){
    bleed = other.bleed;
};

Samurai::~Samurai(){
    std::cout << name << " the Samurai fell in battle.\n";
};


void Samurai::attackAction(int enemyHp, int bleedResistance) {
    buildBleed(45);  

    if (bleed >= bleedResistance) {
        int burstDamage = attack + static_cast<int>(enemyHp * 0.15);
        std::cout << name << " triggers HEMORRHAGE for " << burstDamage << " damage!\n";
        bleed = 0;
    } else {
        std::cout << name << " slashes for " << attack << " damage! "
                  << "[Bleed: " << bleed << "/" << bleedResistance << "]\n";
    }
}

void Samurai::displayInfo(){
    Player::displayInfo();
};

int Samurai::getBleed() { return bleed; };

void Samurai::buildBleed(int buildupAmount) {
    bleed += buildupAmount;
}







