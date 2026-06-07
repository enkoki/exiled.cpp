#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Character{
protected:
    std::string name;
    int hp;
    int maxHp;
    int attack;
    int defense;
    int level;

public:
    Character();
    Character(std::string name, int hp, int attack, int defense, int level);
    Character(const Character& other);

    virtual ~Character();
    
    virtual void attackAction();
    virtual void displayInfo();

    std::string getName();
    int getHp();
    int getMaxHp();
    int getAttack();
    int getDefense();
    int getLevel();

    bool isAlive();
    void takeDamage(int damage);
};

#endif