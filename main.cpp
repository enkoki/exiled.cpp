#include "Character.h"
#include "Player.h"
#include "Warrior.h"
#include "Enemy.h"
#include <cstddef>
#include <iostream>

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
    std::cout << "===== Welcome to Exiled =====\n";
    std::string name = getName();
    int classChoice = chooseClass();
    
    Player* player = nullptr;
    if(classChoice == 1){
        player = new Warrior(name, 110, 26, 11, 8, 0, 0, 0);
        std::cout << "You choose Warrior, Tarnished " << player->getName() << '\n';
    }
    else{
        std::cout << "Class Not Available yet";
        return 0;
    }

    std::cout << "Thou are welcomed, Tarnished " << name << "!\n";

    delete player;
    return 0;
}