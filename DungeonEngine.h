#ifndef DUNGEONENGINE_H
#define DUNGEONENGINE_H

#include <iostream>
#include <string>

class Character {
private:
    std::string name;
    int health;
    int attackPower;
    int defense;

public:
    Character();
    Character(const std::string &n, int h, int a, int d);
    Character(const Character &source);

    std::string getName() const { return name; }
    bool isAlive() const { return health > 0; }

    Character operator+(int heal) const;
    Character operator-(int damage) const;

    bool operator>(const Character &other) const;
    bool operator==(const Character &other) const;

    friend std::ostream& operator<<(std::ostream &os, const Character &c);
};

Character::Character() : name("Unknown Warrior"), health(100), attackPower(10), defense(5) {}

Character::Character(const std::string &n, int h, int a, int d)
    : name(n), health(h), attackPower(a), defense(d) {}

Character::Character(const Character &source)
    : name(source.name),
      health(source.health),
      attackPower(source.attackPower),
      defense(source.defense) {}

Character Character::operator+(int heal) const {
    Character copy = *this;
    copy.health += heal;
    return copy;
}

Character Character::operator-(int damage) const {
    Character copy = *this;
    int actualDamage = damage - copy.defense;
    if (actualDamage < 0) actualDamage = 0;
    copy.health -= actualDamage;
    if (copy.health < 0) copy.health = 0;
    return copy;
}

bool Character::operator>(const Character &other) const {
    return attackPower > other.attackPower;
}

bool Character::operator==(const Character &other) const {
    return name == other.name
        && health == other.health
        && attackPower == other.attackPower
        && defense == other.defense;
}

ostream& operator<<(ostream &os, const Character &c) {
    os << "[" << c.name << " | HP: " << c.health
       << " | ATK: " << c.attackPower << " | DEF: " << c.defense << "]";
    return os;
}

#endif