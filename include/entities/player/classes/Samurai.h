#ifndef SAMURAI_H
#define SAMURAI_H

#include "Player.h"

class Samurai : public Player{
private:
    int bleed;
public:
    Samurai();
    Samurai(std::string name, int hp, int attack, int defense, int level, int exp, int gold, int bleed);
    Samurai(const Samurai& other);

    virtual ~Samurai();

    virtual void attackAction(int enemyHp, int bleedResistance);
    virtual void displayInfo() override;

    int getBleed();

    void buildBleed(int buildupAmount);
};

#endif