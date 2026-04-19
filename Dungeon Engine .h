#ifndef DUNGEONENGINE.h
#define DUNGEONENGINE.h
#include <iostream>
#include <string>
using namespace std;
class Hero {
private:
    string name;
    int health;
    int attackPower;

public:
    // --- 1. Function Overloading (Constructors/Inits) ---
    // Default: Basic stats
    Hero(); 

    // Parameterized: Custom name and stats
    Hero(string n, int h, int a);

    // Copy: Creating a "Shadow" or "Clone" of another hero
    Hero(const Hero &other);

    // --- 2. Operator Overloading ---
    
    // Arithmetic: Hero + HealthPotion (Increases health)
    Hero operator+(int healAmount);

    // Arithmetic: Hero - Damage (Decreases health based on defense)
    Hero operator-(int damage);

    // Comparison: Compare level or strength of two heroes
    bool operator==(const Hero &other) const;

    // Output: Display HUD (Friend Function)
    friend ostream& operator<<(ostream &os, const Hero &h);
    
    // Extra helper to check state
    bool isAlive() const { return health > 0; }
};

#endif