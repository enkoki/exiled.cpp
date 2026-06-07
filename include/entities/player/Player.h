#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character{
private:
    int exp;
    int expToLevel;
    int gold;
    std::string className;

public:
    Player();
    Player(std::string name, int hp, int attack, int defense, int level, int exp, int gold);
    Player(const Player& other);

    virtual ~Player();

    virtual void attackAction() override;
    virtual void displayInfo() override;

    int getExp();
    int getExpToLevel();
    int getGold();

    void gainExperience(int amt);
    void levelUp();
};

#endif