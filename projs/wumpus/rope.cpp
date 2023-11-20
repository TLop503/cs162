#include "rope.h"

#include <iostream>

using namespace std;

//Bats Implementation
void Rope::assert_type() {
    cout << "I'm a rope" << endl;
}

void Rope::do_event(Player &p) {
    if (p.has_gold) {
        cout << "You find your way back to the start and leave the cave." << endl;
        p.win = true;
    }
}