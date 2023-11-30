#include "bats.h"

#include <iostream>

using namespace std;

//Bats Implementation
void Bats::assert_type() {
    cout << "I'm a bat" << endl;
}

void Bats::do_event(Player &p) {
    cout << "Bats disorient you." << endl;
    p.bat_duration = 5;
}