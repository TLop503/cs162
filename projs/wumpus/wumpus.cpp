#include "wumpus.h"

#include <iostream>

using namespace std;

//Wumpus Implementation
void Wumpus::assert_type() {
    cout << "I'm a wumpus" << endl;
}

void Wumpus::do_event(Player &p) {
    cout << "The wumpus eats you. Womp Womp." << endl 
    <<"Game over" << endl 
    << "Your score was: 0" << endl;
    
    p.is_alive = false;
}


void Wumpus::special_action() {
    if (alive) {
        wumpus_walk();
    }
}




