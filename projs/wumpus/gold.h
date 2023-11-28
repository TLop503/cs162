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
/**************************************************
 * Name: non-default constructor
 * Description: sets x and y to given values, symbol to 'g', and percept to "You see a glimmer nearby."
 * Parameters: ints x and y for x and y coordinates
 * Pre-conditions: event has been properlay allocated and a pointer to this has been made in the event grid
 * Post-conditions: gold will exist
 ***********************************************/
        Gold(int x, int y) : Event(x,y) {
            this->x = x;
            this->y = y;
            this->symbol = 'g';
            this->percept = "You see a glimmer nearby.";
        }

/**************************************************
 * Name: assert_type
 * Description: debug function to check type, not used in prod
 ***********************************************/
        void assert_type();

/**************************************************
 * Name: do_event
 * Description: player gets gold and symbol and percept evaporate
 * Parameters: valid player PBR
 * Pre-conditions: 
 * Post-conditions: player will have gold and become able to win by finding the rope
 ***********************************************/
        void do_event(Player &p);
};


#endif