#include "Battle.h"
#include "ascii/UI.h"
#include <iostream>
#include <unistd.h>

Battle::Battle(Player *player, Enemy *enemy) {

  this->player = player;
  this->enemy = enemy;

  playerWon = false;
  fled = false;
}

Battle::~Battle() { std::cout << "The Battle has ended!\n"; }

void Battle::showStats() {

  UI::battleHeader();

  UI::battleStats(player->getName(), player->getHp(), player->getMaxHp(),
                  player->getAttack(), player->getDefense(),

                  enemy->getName(), enemy->getHp(), enemy->getMaxHp(),
                  enemy->getAttack(), enemy->getDefense());
}

bool Battle::isOver() {

  return !player->isAlive() || !enemy->isAlive() || fled;
}

bool Battle::didPlayerWin() { return enemy->getHp() <= 0; }

bool Battle::didPlayerFlee() { return fled; }

void Battle::playerTurn() {

  int choice{};

  while (true) {

    UI::battleMenu();

    std::cin >> choice;

    switch (choice) {

    case 1:

      player->attackAction();

      enemy->takeDamage(player->getAttack());

      return;

    case 2:

      std::cout << "Work In Progress\n";

      break;

    case 3:

      std::cout << "You fled from the battle!\n";

      fled = true;

      return;

    default:

      std::cout << "Invalid Choice\n";

      break;
    }
  }
}

void Battle::enemyTurn() {

  std::cout << "\n";

  enemy->attackAction();

  player->takeDamage(enemy->getAttack());
}

void Battle::start() {

  sleep(1);

  std::cout << "\n"
            << "A wild " << enemy->getName() << " appears!\n";

  sleep(1);

  while (!isOver()) {

    showStats();
    playerTurn();

    if (isOver()) {
      break;
    }

    sleep(1);

    std::cout << "\n"
              << "----- Enemy Turn -----\n";

    enemyTurn();

    sleep(1);
  }

  std::cout << "\n";

  if (didPlayerFlee()) {

    std::cout << "You escaped safely.\n";

    return;
  }

  if (didPlayerWin()) {

    std::cout << "You defeated " << enemy->getName() << "!\n";

    sleep(1);

    player->gainExperience(enemy->getExpReward());

  } else {

    sleep(1);

    std::cout << "You have been slain, Tarnished.\n";
  }
}