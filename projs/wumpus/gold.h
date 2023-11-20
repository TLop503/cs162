#ifndef GOLD_H
#define GOLD_H 

//Gold Interface
#include "gold.h"
#include "event.h"

#include <iostream>

using namespace std;

//Wumpus Implementation
class Gold : public Event {
    private:
    public:
        Gold(int x, int y) : Event(x,y) {
            this->x = x;
            this->y = y;
            this->symbol = 'g';
            this->percept = "You see a glimmer nearby.";
        }

        void assert_type();    
        void do_event(Player &p);
};


#endif