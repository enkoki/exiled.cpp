#pragma once
#include <string>

namespace UI {

    void clearScreen();

    void printLine(char character = '=', int length = 60);

    void pause();

    void logoutAnimation();

    void mainMenu();

    void statusHeader();

    void battleHeader();

    void battleStats(
        const std::string& playerName,
        int playerHp,
        int playerMaxHp,
        int playerAttack,
        int playerDefense,
        const std::string& enemyName,
        int enemyHp,
        int enemyMaxHp,
        int enemyAttack,
        int enemyDefense
    );

    void battleMenu();
}