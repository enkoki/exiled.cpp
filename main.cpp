#include "Character.h"
#include "Player.h"
#include "Warrior.h"
#include "Enemy.h"
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
    
    std::cout << "Thou are welcomed, Tarnished " << name << "!\n";
    return 0;
}