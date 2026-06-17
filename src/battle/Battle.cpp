#include "Battle.h"
#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <unistd.h>

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

void Battle::playerTurn(){
    int ongoing = 1;
    int choice;
    while (true){
        std::cout << "1. Attack\n2. Bag [WIP]\n3. Run\n";
        std::cin >> choice;
        if (choice == 3){
            break;
        }
        switch(choice){
            case 1:
                player->attackAction();
                enemy->takeDamage(player->getAttack());
                return;
            case 2:
                std::cout << "Work In Progress\n";
                break;
            default:
                std::cout << "Invalid Choice\n";
        }
    }
}

void Battle::enemyTurn(){
    enemy->attackAction();
    player->takeDamage(enemy->getAttack());
}

void Battle::start(){
    sleep(1);
    std::cout << "A wild " << enemy->getName() << " appears!\n";
    sleep(1);
    while(!isOver()){
        showStats();
        playerTurn();
        if(isOver()) break;
        sleep(1);
        enemyTurn();
        sleep(1);
    }
    if(didPlayerWin()){
        std::cout << "You defeated " << enemy->getName() << "!\n";
        sleep(1);
        player->gainExperience(enemy->getExpReward());
    } else {
        sleep(1);
        std::cout << "You have been slain, Tarnished.\n";
    }
}