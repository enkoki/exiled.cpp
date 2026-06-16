#include "Player.h"
#include "Samurai.h"
#include "Warrior.h"
#include "Enemy.h"
#include <iostream>
#include <unistd.h>

void logOutAnimation(){
    std::cout << "\nLogging Off ";
    std::cout.flush();
    for(int i = 0; i < 5; i++){
        usleep(500000); // 0.5s
        std::cout << ". ";
        std::cout.flush();
    }
    std::cout << "\n";
}

std::string getName() {
    using namespace std;
    string name;
    cout << "Enter your name: ";
    cin >> name;
    return name;
}

int chooseClass() {
    using namespace std;
    cout << "1. Warrior\n2. Samurai\n3. Druid\n4. Witch\n";
    cout << "Select Class: ";
    int c;
    cin >> c;
    return c;
}

int main() {
    std::cout << "\n===== Welcome to Exiled =====\n";
    std::string name = getName();
    int classChoice = chooseClass();
    
    Player* player = nullptr;
    switch(classChoice){
        case 1:
            player = new Warrior(name, 110, 26, 11, 8, 0, 0, 0);
            sleep(1);
            std::cout << "You choose Warrior, " << player->getName() << '\n';
            break;
        case 2:
            player = new Samurai(name, 120, 27, 13, 9, 0, 0, 0);
            sleep(1);
            std::cout << "You choose Samurai, " << player->getName() << '\n';
            break;
        case 3: break;
        case 4: break;
        default:
            std::cout << "Class Not Available yet";
            return 404;
    }

    sleep(1);
    std::cout << "Thou are welcomed, Tarnished\n";
    sleep(1);
    std::cout << "Press Enter to Start the Game\n";
    std::cin.ignore();
    std::cin.get();

    while(1){
        std::cout << "\n===== Main Menu =====\n";
        std::cout << "1. Battle\n2. Dungeon\n3. Status\n4. Inventory (WIP)\n5. Exit\nSelect Action: ";
        int menuChoice {};
        std::cin >> menuChoice;
        if(menuChoice == 5){
            break;
        }
        switch(menuChoice){
            case 1: break;
            case 2: break;
            default: std::cout << "Invalid choice.\n"; break;
        }
    }

    logOutAnimation();
    delete player;
    return 0;
}