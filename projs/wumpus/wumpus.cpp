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


void Wumpus::wumpus_walk(){
    int xdir, ydir;
    bool good_dir = false;
    do {
        xdir = ((rand() % 3) - 1);
        ydir = ((rand() % 3) - 1);
        
        if (x + xdir >= 0 && x + xdir < xlim && y + ydir >= 0 && y + ydir < ylim) {
            good_dir = true;
        }
    } while (!good_dir); //maybe make this a while loop?
    if (rand() % 2) {
        x = x + xdir;
    }
    else {
        y = y + ydir;
    }
}

