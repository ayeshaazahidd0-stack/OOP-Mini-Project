#include <iostream>
#include git add "Dungeon Exploration & Combat Engine Library.cpp" DungeonEngine.h
git commit -m "Add dungeon engine demo"
git push origin main"DungeonEngine.h"
using namespace std;

int main() {
    Character player("Ayesha", 120, 25, 8);
    Character defaultEnemy;
    Character shadowPlayer = player;

    cout << "--- Dungeon Initialization ---" << endl;
    cout << "Player: " << player << endl;
    cout << "Enemy:  " << defaultEnemy << endl;
    cout << "Shadow: " << shadowPlayer << endl << endl;

    cout << "An enemy strikes " << player.getName() << " for 30 damage!" << endl;
    player = player - 30;
    cout << "Result: " << player << endl << endl;

    cout << "You find a Health Potion! +15 HP" << endl;
    player = player + 15;
    cout << "Result: " << player << endl << endl;

    cout << "Checking battle strength..." << endl;
    if (player > defaultEnemy) {
        cout << player.getName() << " is stronger than " << defaultEnemy.getName() << "!" << endl;
    }

    if (player == shadowPlayer) {
        cout << "They are the same person." << endl;
    } else {
        cout << "The shadow is a different entity." << endl;
    }

    cout << "\n--- Adventure End ---" << endl;
    return 0;
}