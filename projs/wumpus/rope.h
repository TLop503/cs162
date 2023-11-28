#ifndef ROPE_H
#define ROPE_H 

#include "event.h"

//Bats Interface
class Rope : public Event {
    private:
    public:
/**************************************************
 * Name: non-default constructor
 * Description: creates rope with coordinates and symbol 'r'
 * Parameters: int coords
 * Pre-conditions: 
 * Post-conditions: rope will exist. note this is only for debug mode so that the player can find the exit
 * no notable impact on gameplay, just used for winning
 ***********************************************/
    Rope(int x, int y) : Event(x,y) {
        this->x = x;
        this->y = y;
        this->symbol = 'r';
        this->percept = "";
    }

/**************************************************
 * Name: assert_type
 * Description: debug function to assert type
 ***********************************************/
    void assert_type();

/**************************************************
 * Name: do_event
 * Description: if player has gold player will be set to win
 * Parameters: valid player PBR
 * Pre-conditions: 
 * Post-conditions: player may win
 ***********************************************/
    void do_event(Player &p);
};


#endif