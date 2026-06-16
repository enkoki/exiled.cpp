#ifndef BATTLE_H
#define BATTLE_H

#include "Enemy.h"
#include "Player.h"
class Battle{
private:
    Player* player;
    Enemy* enemy;
    bool playerWon;
public:
    Battle(Player* player, Enemy* enemy);
    ~Battle();

    void start();
    void showStats();
    void playerTurn();
    void enemyTurn();
    bool isOver();
    bool didPlayerWin();
};

#endif