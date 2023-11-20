#include "stalactites.h"

#include <iostream>

using namespace std;

//Stalactites Implementation
void Stalactites::assert_type(){
    cout << "I'm a stalactite" << endl;
}

void Stalactites::do_event(Player& p) {
    if (rand() % 2) {
        cout << "You were struck by a falling stalactite. Womp womp."
        << endl << "Score: 0"
        << endl << "Game Over."
        << endl;
        p.is_alive = false;
    }

}