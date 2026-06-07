#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"
class Warrior : public Player{
private:
    int rage;
public:
    Warrior();
    Warrior(std::string name, int hp, int attack, int defense, int level, int exp, int gold, int rage);
    Warrior(const Warrior& other);

    virtual ~Warrior();

    virtual void attackAction() override;
    virtual void displayInfo() override;

    int getRage();

    void buildRage();
};

#endif