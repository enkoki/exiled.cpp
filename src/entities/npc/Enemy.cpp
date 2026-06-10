#include "Enemy.h"
#include <iostream>

Enemy::Enemy() : Character() {
    expReward = 0;
    goldReward = 0;
    enemyType = "Goblin";
}

Enemy::Enemy(std::string name, int hp, int attack, int defense, int level, int expReward, int goldReward, int bleedResistance,  std::string enemyType) 
    : Character(name, hp, attack, defense, level) {
        this->expReward = expReward;
        this->goldReward = goldReward;
        this->bleedResistance = bleedResistance;
        this->enemyType = enemyType;
}

Enemy::Enemy(const Enemy& other): Character(other){
    expReward = other.expReward;
    goldReward = other.goldReward;
    bleedResistance = other.bleedResistance;
    enemyType = other.enemyType;
} 

Enemy::~Enemy(){
    std::cout << enemyType << " has fallen into the void.\n";
}

void Enemy::attackAction() {
    std::cout << enemyType << " " << name << " attacks you for " << attack << " damage!\n";
}

void Enemy::displayInfo() {
    std::cout << "=== Enemy Info ===\n";
    std::cout << "Type: " << enemyType << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "HP: " << hp << "/" << maxHp << "\n";
    std::cout << "Attack: " << attack << "\n";
    std::cout << "Defense: " << defense << "\n";
    std::cout << "Level: " << level << "\n";
}

int Enemy::getExpReward(){ return expReward; }
int Enemy::getGoldReward(){ return goldReward; }
std::string Enemy::getEnemyType(){ return enemyType; }