#include "gold.h"

#include <iostream>

using namespace std;

//Gold Implementation
void Gold::assert_type() {
    cout << "I'm gold" << endl;
}

void Gold::do_event(Player &p) {
    cout << "You pick up the gold." << endl;
    p.has_gold = true;

    //disapear
    this->symbol = ' ';
    this->percept = "";
}