#include "EnemyFactory.h"

#include <cstdlib>
#include <vector>

namespace {

    struct EnemyData {
        const char* name;
        int hp;
        int attack;
        int defense;
        int level;
        int expReward;
        int goldReward;
        int bleedResistance;
        const char* enemyType;
    };

    const std::vector<EnemyData> enemyList = {
        {
            "Goblin",
            50,
            10,
            3,
            1,
            30,
            10,
            5,
            "Goblin"
        },
        {
            "Bandit",
            70,
            14,
            5,
            2,
            45,
            18,
            10,
            "Bandit"
        },
        {
            "Hollow Knight",
            100,
            18,
            8,
            3,
            70,
            30,
            15,
            "Knight"
        }
    };

}

Enemy* EnemyFactory::createRandomEnemy() {
    int index = std::rand() % enemyList.size();

    const EnemyData& data = enemyList[index];

    return new Enemy(
        data.name,
        data.hp,
        data.attack,
        data.defense,
        data.level,
        data.expReward,
        data.goldReward,
        data.bleedResistance,
        data.enemyType
    );
}