#include "Battle.h"
#include "Enemy.h"
#include "EnemyFactory.h"
#include "Player.h"
#include "Samurai.h"
#include "Warrior.h"
#include "ascii/Colors.h"
#include "ascii/Logo.h"
#include "ascii/UI.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <unistd.h>

std::string getName() {
    std::string name;

    std::cout << "\n"
              << Color::Yellow
              << "              Tarnished, what is your name?\n"
              << Color::Reset
              << "\n"
              << "              > ";

    std::getline(std::cin, name);

    return name;
}

int chooseClass() {
    std::cout << "\n"
              << Color::Bold << Color::White
              << "                     CHOOSE YOUR CLASS\n"
              << Color::Reset;

    UI::printLine('-');

    std::cout << "\n"
              << "              " << Color::Yellow << "[1]" << Color::Reset
              << " Warrior\n"
              << "                  " << Color::Gray
              << "A resilient fighter with balanced strength.\n"
              << Color::Reset
              << "\n"
              << "              " << Color::Yellow << "[2]" << Color::Reset
              << " Samurai\n"
              << "                  " << Color::Gray
              << "A swift warrior skilled with deadly weapons.\n"
              << Color::Reset
              << "\n"
              << "              " << Color::Yellow << "[3]" << Color::Reset
              << " Druid\n"
              << "                  " << Color::Gray
              << "Class currently unavailable.\n"
              << Color::Reset
              << "\n"
              << "              " << Color::Yellow << "[4]" << Color::Reset
              << " Witch\n"
              << "                  " << Color::Gray
              << "Class currently unavailable.\n"
              << Color::Reset
              << "\n";

    UI::printLine('-');

    std::cout << "\n"
              << "              " << Color::Cyan
              << "Select Class"
              << Color::Reset
              << ": ";

    int choice{};
    std::cin >> choice;

    return choice;
}

int main() {
    std::srand(std::time(nullptr));

    UI::clearScreen();
    ASCII::printLogo();

    std::string name = getName();

    UI::clearScreen();
    ASCII::printLogo();

    int classChoice = chooseClass();
    Player* player = nullptr;

    switch (classChoice) {
        case 1:
            player = new Warrior(name, 110, 26, 11, 8, 0, 0, 0);

            sleep(1);

            std::cout << "\n"
                      << Color::Green
                      << "              ✓ Warrior selected, "
                      << player->getName()
                      << "\n"
                      << Color::Reset;
            break;

        case 2:
            player = new Samurai(name, 120, 27, 13, 9, 0, 0, 0);

            sleep(1);

            std::cout << "\n"
                      << Color::Green
                      << "              ✓ Samurai selected, "
                      << player->getName()
                      << "\n"
                      << Color::Reset;
            break;

        case 3:
        case 4:
            std::cout << "\n"
                      << Color::Yellow
                      << "              This class is not available yet.\n"
                      << Color::Reset;
            return 0;

        default:
            std::cout << "\n"
                      << Color::Red
                      << "              ✗ Invalid class selection.\n"
                      << Color::Reset;
            return 0;
    }

    sleep(1);

    std::cout << "\n"
              << Color::Yellow
              << "              Thou art welcomed, Tarnished.\n"
              << Color::Reset;

    sleep(1);

    std::cout << "\n"
              << Color::Gray
              << "              Press ENTER to begin...\n"
              << Color::Reset;

    std::cin.ignore();
    std::cin.get();

    while (true) {
        UI::clearScreen();
        ASCII::printLogo();
        UI::mainMenu();

        int menuChoice{};
        std::cin >> menuChoice;

        if (menuChoice == 5)
            break;

        switch (menuChoice) {
            case 1: {
                UI::clearScreen();
                ASCII::printLogo();

                Enemy* enemy = EnemyFactory::createRandomEnemy();

                Battle battle(player, enemy);
                battle.start();

                delete enemy;
                UI::pause();

                break;
            }

            case 2:
                std::cout << "\n"
                          << Color::Yellow
                          << "              The dungeon system is still under construction...\n"
                          << Color::Reset;

                UI::pause();
                break;

            case 3:
                UI::clearScreen();
                ASCII::printLogo();
                UI::statusHeader();

                player->displayInfo();

                UI::pause();
                break;

            case 4:
                std::cout << "\n"
                          << Color::Yellow
                          << "              Inventory is currently under construction...\n"
                          << Color::Reset;

                UI::pause();
                break;

            default:
                std::cout << "\n"
                          << Color::Red
                          << "              ✗ Invalid choice.\n"
                          << Color::Reset;

                sleep(1);
                break;
        }
    }

    UI::logoutAnimation();

    delete player;

    return 0;
}