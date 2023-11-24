#ifndef BATS_H
#define BATS_H 

#include "event.h"

/**************************************************
 * Name: Bats class
 * Description: bats will confuse the player and make them move inverted for a bit
 ***********************************************/
class Bats : public Event {
    private:
    public:

/**************************************************
 * Name: non-default constructor
 * Description: creates a bat with given coordinates
 * Parameters: x, y -- coords
 * Pre-conditions: none
 * Post-conditions: bat will exist
 ***********************************************/
    Bats(int x, int y) : Event(x,y) {
        this->x = x;
        this->y = y;
        this->symbol = 'b';
        this->percept = "You hear wings flapping.";
    }

/**************************************************
 * Name: assert_type
 * Description: debug function to verify event is bat
 * Parameters: n/a
 * Pre-conditions: event exists
 * Post-conditions: will cout bat phrase
 ***********************************************/
    void assert_type();
/**************************************************
 * Name: do_event
 * Description: set player's bat counter to 5
 * Parameters: player PBR
 * Pre-conditions: player exists (maybe you could declare a player in the function? idk c++ is weird, just make one first)
 * Post-conditions: player's bat counter will be 5
 ***********************************************/
    void do_event(Player &p);
};


#endif