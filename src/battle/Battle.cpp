#include "Battle.h"
#include "Enemy.h"
#include "Player.h"
#include <iostream>

Battle::Battle(Player* player, Enemy* enemy){
    this->player = player;
    this->enemy = enemy;
};

Battle::~Battle(){
    std::cout << "The Battle has ended!\n";
}

void Battle::showStats(){
    int playerHP = player->getHp();
    int enemyHP = enemy->getHp();   
    std::cout <<"==== Battle ====\n";
    std::cout << player->getName() << " : " << player->getHp() << "/" << player->getMaxHp() <<'\n';
    std::cout << enemy->getName() << " : " << enemy->getHp() << "/" << enemy->getMaxHp() << '\n';

};

bool Battle::isOver(){
    int playerHP = player->getHp();
    int enemyHP = enemy->getHp();
    
    if(playerHP <= 0 || enemyHP <= 0){
        return true;
    }
    return false;
};


bool Battle::didPlayerWin(){
   return enemy->getHp() <= 0;
};