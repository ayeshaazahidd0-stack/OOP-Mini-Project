#include<iostream>
using namespace std;
#include "DungeonEngine.h" 
int main() {
    // Creating heroes using overloaded constructors
    Hero player1("Aurelius", 100, 15);
    Hero player2 = player1; // Uses copy constructor

    cout << "--- A New Adventure Begins ---" << endl;
    cout << player1 << endl;

    // Simulating a trap using the - operator
    cout << "You stepped on a spike trap! -20 HP" << endl;
    player1 = player1 - 20; 

    // Simulating a potion using the + operator
    cout << "You found a small potion! +10 HP" << endl;
    player1 = player1 + 10;

    cout << "\nUpdated Stats:\n" << player1;

    return 0;
}
/*Problem Statement
Design and implement a custom C++ library (header file) based on a problem of your
choice. Your class must demonstrate the use of function overloading and operator
overloading, and the library must be used in a separate .cpp file to show all
functionalities.
Functional Requirements
1. Custom Class Design
● Create a class relevant to your chosen problem
● Include appropriate data members and member functions
2. Function Overloading (Mandatory)
Implement at least 3 overloaded functions (same name, different parameters), for
example:
● Default initialization
● Parameterized initialization
● Copy or alternate input method
3. Operator Overloading (Mandatory)
Overload at least 4 operators, including:
● At least 2 arithmetic operators (e.g., +, -, *)
● At least 1 comparison operator (e.g., ==, <)
● << for output display (friend function)*/
