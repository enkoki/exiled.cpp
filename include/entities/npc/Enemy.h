#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include <string>
class Enemy : public Character{
private:
    int expReward;
    int goldReward;
    int bleedResistance;
    std::string enemyType;

public:
    Enemy();
    Enemy(std::string name, int hp, int attack, int defense, int level, int expReward, int goldReward, int bleedResistance, std::string enemyType);
    Enemy(const Enemy& other);

    virtual ~Enemy();

    virtual void attackAction() override;
    virtual void displayInfo() override;

    int getExpReward();
    int getGoldReward();
    int getBleedResistance();
    
    std::string getEnemyType();

};

#endif