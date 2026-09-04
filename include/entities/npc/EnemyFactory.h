#ifndef ENEMY_FACTORY_H
#define ENEMY_FACTORY_H

#include "Enemy.h"

class EnemyFactory {
public:
    static Enemy* createRandomEnemy();
};

#endif