#ifndef DUNGEONENGINE_H
#define DUNGEONENGINE_H
#include <iostream>
#include <string>
using namespace std;
class Character {
private:
    string name;
    int health;
    int attackPower;
    int defense;

public:
    Character();

    Character(string n, int h, int a, int d);
  
    Character(const Character &source);

    string getName() const { return name; }
    bool isAlive() const { return health > 0; }

    Character operator+(int heal);
    Character operator-(int damage);

    bool operator>(const Character &other) const;

    bool operator==(const Character &other) const;

    
    friend ostream& operator<<(ostream &os, const Character &c);
};

Character::Character() : name("Unknown Warrior"), health(100), attackPower(10), defense(5) {}

Character::Character(string n, int h, int a, int d) 
  : name(n), health(h), attackPower(a), defense(d) {}

Character::Character(const Character &source) {
    name = source.name + " (Clone)";
    health = source.health;
    attackPower = source.attackPower;
    defense = source.defense;
}

Character Character::operator+(int heal) {
    this->health += heal;
    return *this;
}

Character Character::operator-(int damage) {
    int actualDamage = damage - this->defense;
    if (actualDamage < 0) actualDamage = 0;
    this->health -= actualDamage;
    if (this->health < 0) this->health = 0;
    return *this;
}

bool Character::operator>(const Character &other) const {
    return this->attackPower > other.attackPower;
}

bool Character::operator==(const Character &other) const {
    return this->name == other.name;
}

std::ostream& operator<<(std::ostream &os, const Character &c) {
    os << "[" << c.name << " | HP: " << c.health << " | ATK: " << c.attackPower << " | DEF: " << c.defense << "]";
    return os;
}

#endif