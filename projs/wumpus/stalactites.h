#ifndef STALACTITES_H
#define STALACTITES_H

#include "event.h"

//Stalactites Interface
class Stalactites : public Event {
    private:
    public:
/**************************************************
 * Name: stalactites non-default constructor
 * Description: creates stalactites with coordinates and symbol 's'
 * Parameters: int coords
 ***********************************************/
        Stalactites(int x, int y) : Event(x,y) {
            this->x = x;
            this->y = y;
            this->symbol = 's';
            this->percept = "You hear water dripping";
        }

/**************************************************
 * Name: assert_type
 * Description: debug function to assert type
 ***********************************************/
        void assert_type();

/**************************************************
 * Name: do_event
 * Description: 50% chance for player to be killed
 * Parameters: valid player PBR
 * Pre-conditions: 
 * Post-conditions: player may die
 ***********************************************/
        void do_event(Player &p);
};

#endif
